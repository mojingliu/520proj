module PatternC where

import qualified Data.Map as M
import Data.Map (Map, (!))
import Data.List
import Text.PrettyPrint.Leijen

import Control.Monad
import Control.Monad.Reader

import C
import Args
import Types

data Env = Env { _vmap :: Map Arg [Int]
               , _iamap :: Map (Int,Int) Int
               , _samap :: Map (Int,Int) Int
               , _ics :: [(Int, Int)] -- (i,j) => ints[i] == j should be checked
               , _scs :: [(Int, String)] -- strcmp(strings[i
               }
         deriving(Eq, Show)

-- Commenting of patterns
comment :: Pattern -> Doc  -- FIXME comment conditions
comment ((a,_) :-->: b) = text "/*" <$> indent ind_amt
                      (vsep (map com a) <$> text "----->" <$> vsep (map com b))
                      <$> pretty "*/"

com (BC i as) = text (bmap!i) <+> hsep (map f as)
    where f (IConst i) = pretty i
          f (Str s) = dquotes $ pretty s
          f (IVar x) = pretty $ "xyzlmnkjkpqr"!!x
          f (SVar x) = pretty $ "stuvw"!!x
          f (CExp s) = empty -- FIXME

-- getting the argument-index maps
massage :: (Int, Bytecode) -> [(Int, Int, Arg)]
massage (i1, (BC n args)) = map (uncurry ((,,) i1)) (zip [0..] args)

iallindices :: [Bytecode] -> [(Int, Int, Arg, Int)]
iallindices = map f . flip zip [0..] . filter isarg . concatMap massage . zip [0..]
    where isarg (_,_,x) = isIArg x
          f ((a,b,c),d) = (a,b,c,d)

iargmap :: [Bytecode] -> Map (Int, Int) Int
iargmap = M.fromList . map f . iallindices
    where f (i,j,_,ix) = ((i,j),ix)

ivarmap :: [Bytecode] -> Map Arg [Int]
ivarmap = M.fromListWith (++) . map f . filter isvar . iallindices
    where isvar (_,_,x,_) = isIVar x
          f (_,_,x,ix) = (x, [ix])

sallindices :: [Bytecode] -> [(Int, Int, Arg, Int)]
sallindices = map f . flip zip [0..] . filter isarg . concatMap massage . zip [0..]
    where isarg (_,_,x) = isSArg x
          f ((a,b,c),d) = (a,b,c,d)

sargmap :: [Bytecode] -> Map (Int, Int) Int
sargmap = M.fromList . map f . sallindices
    where f (i,j,_,ix) = ((i,j),ix)

svarmap :: [Bytecode] -> Map Arg [Int]
svarmap = M.fromListWith (++) . map f . filter isvar . sallindices
    where isvar (_,_,x,_) = isSVar x
          f (_,_,x,ix) = (x, [ix])

-- (INDEX, CONST)!!
iconsts :: [Bytecode] -> [(Int, Int)]
iconsts = map f . filter isconst . iallindices
    where isconst (_,_,IConst _,_) = True
          isconst _ = False
          f (_,_,IConst x,ix) = (ix, x)

sconsts :: [Bytecode] -> [(Int, String)]
sconsts = map f . filter isconst . sallindices
    where isconst (_,_,Str _,_) = True
          isconst _ = False
          f (_,_,Str x,ix) = (ix, x)

makeMaps :: [Bytecode] -> Env
makeMaps bs = Env (M.union (ivarmap bs) (svarmap bs)) (iargmap bs) (sargmap bs) (iconsts bs) (sconsts bs)

-- compile, gets C function from a named pattern
doIT :: Pat -> Doc
doIT p@(Pat _ q) = comment q <$> pretty (compile p)

compile :: Pat -> Fn
compile (Pat n p) = Fn IntT n [Param (Ptr (Ptr (X "CODE"))) "c"] (go p)

go :: Pattern -> [Stmt]
go p@(b@(bs, cs) :-->: a) = decls ++ [Ift pres rplc, Return 0]
    where 
      decls = intdec ++ strdec 
      intdec = if (M.size . _iamap $ env) > 0
               then [Decl IntT [(Arry "ints" (M.size . _iamap $ env))]]
               else []
      strdec = if (M.size . _samap $ env) > 0
               then [Decl (Ptr CharT) [(Arry "strings" (M.size . _samap $ env))]]
               else []
      pres = runReader (preConds b) env
      rplc = runReader (replace p) env
      env = makeMaps bs

replace :: Pattern -> Reader Env Stmt
replace ((b,_) :-->: a) = do
  pc <- postConds a
  return $ Block $ [Return (Inv "replace_modified" ([Ident "c", Int (length b)] ++ [pc]))]

postConds :: [Bytecode] -> Reader Env Exp
postConds bs = do
  calls <- mapM cMake bs
  return $ foldr ($) (Ident "NULL") calls

-- beautifully expressive function names
cMake :: Bytecode -> Reader Env (Exp -> Exp)
cMake (BC b args) = do
  m <- asks _vmap
  ps <- mapM fixArg args
  return $ \e -> Inv (make b) (ps ++ [e])

fixArg :: Arg -> Reader Env Exp
fixArg x@(IVar _) = do
  m <- asks _vmap
  return $ Arr "ints" (Int (head $ m!x))

fixArg x@(SVar _) = do
  m <- asks _vmap
  return $ Arr "strings" (Int (head $ m!x))

fixArg (IConst z) = return $ Int z
fixArg (CExp vs) = do
  ss <- mapM fixAArg vs
  return $ PExp $ concat ss

fixAArg :: AArg -> Reader Env String
fixAArg (A y) = (show . pretty) `fmap` fixArg y
fixAArg (S s) = return s

iconstCheck :: (Int,Int) -> Exp
iconstCheck (i,j) = Eql (Arr "ints" (Int i)) (Int j)

sconstCheck :: (Int,String) -> Exp
sconstCheck (i,s) = Eql (Inv "strcmp" [(Arr "strings" (Int i)), St s]) (Int 0)

preConds :: ([Bytecode], [Cond]) -> Reader Env Pred
preConds (bs, conds) = do
  ics <- asks _ics
  scs <- asks _scs
  args <- mapM pred2 $ zip [0..] bs
  dconds <- mapM doCond conds
  vs <- asks (filter ((>1) . length) . M.elems . _vmap) -- the variables with equality checks
  return $ Conj (args ++ map iconstCheck ics ++ map sconstCheck scs++ concatMap eqCheck vs ++ dconds)

-- precondition: input has length two or greater
eqCheck :: [Int] -> [Exp]
eqCheck (x:xs) = map (Eql (Arr "ints" (Int x))) . map (Arr "ints") . map Int $ xs

doCond :: Cond -> Reader Env Exp
doCond (Indegree x n) = do
  m <- asks _vmap
  return $ Lte (Field (Arr "currentlabels"
                       (Arr "ints" (Int (head $ m!x))))
                "sources")
                (Int n)

-- builds a predicate from a bytecode instruction
pred2        :: (Int, Bytecode) -> Reader Env Exp
pred2 (i, b@(BC _ args)) = do
  let idxs = [(i, j) | (_, j) <- zip args [0..]]
  realArgs <- mapM getIdx idxs
  return $ Inv (cPred b) ([instr i] ++ realArgs) -- get args

getIdx :: (Int, Int) -> Reader Env Exp
getIdx x = do
  im <- asks _iamap
  sm <- asks _samap
  let Just z = (liftM IVar $ M.lookup x im) `mplus` (liftM SVar $ M.lookup x sm)
  return $ case z of
             (IVar y) -> (Addr (Arr "ints" (Int y)))
             (SVar y) -> (Addr (Arr "strings" (Int y)))


wrapNext :: Exp -> Exp
wrapNext s = Inv "next" [s]

instr :: Int -> Exp
instr n = (iterate wrapNext (Ident "*c")) !! n
