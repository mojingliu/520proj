module Types where

import C

import Data.Map (Map, (!))
import qualified Data.Map as M

-- bytecode stuff
data Bytecode = BC Instr [Arg]
              deriving(Show, Eq)


data Instr = Nop
           | I2c
           | New
           | Instanceof
           | Checkcast
           | Imul 
           | Ineg
           | Irem
           | Isub
           | Idiv
           | Iadd
           | Iinc
           | Label
           | Goto
           | Ifeq
           | Ifne
           | If_acmpeq
           | If_acmpne
           | Ifnull
           | Ifnonnull
           | If_icmpeq
           | If_icmpgt
           | If_icmplt
           | If_icmple
           | If_icmpge
           | If_icmpne
           -- isif
           | Ireturn
           | Areturn
           | RReturn
           | Aload
           | Astore
           | Iload
           | Istore
           | Dup 
           | Pop 
           | Swap
           | LdcInt 
           | LdcString
           | Aconst_null
           | Getfield
           | Putfield
           | Invokevirtual
           | Invokenonvirtual
             deriving(Show, Eq, Ord)

nop = BC Nop []
i2c = BC I2c []
new x = BC New [x]
instanceof x = BC Instanceof [x]
checkcast x = BC New [x]
imul = BC Imul []
ineg = BC Ineg []
irem = BC Irem []
isub = BC Isub []
idiv = BC Idiv []
iadd = BC Iadd []
iinc x y = BC Iinc [x, y]
label x = BC Label [x]
goto x = BC Goto [x]
ifeq x = BC Ifeq [x]
ifne x = BC Ifne [x]
if_acmpeq x = BC If_acmpeq [x]
if_acmpne x = BC If_acmpne [x]
ifnull x = BC Ifnull [x]
ifnonnull x = BC Ifnonnull [x]
if_icmpeq x = BC If_icmpeq [x]
if_icmpgt x = BC If_icmpgt [x]
if_icmplt x = BC If_icmplt [x]
if_icmple x = BC If_icmple [x]
if_icmpge x = BC If_icmpge [x]
if_icmpne x = BC If_icmpne [x]
--is_if
ireturn = BC Ireturn []
areturn = BC Areturn []
rreturn = BC RReturn []
aload x = BC Aload [x]
astore x = BC Astore [x]
iload x = BC Iload [x]
istore x = BC Istore [x]
dup = BC Dup []
pop = BC Pop []
swap = BC Swap []
ldcint x = BC LdcInt [x]
ldcstr x = BC LdcString [x]
aconst_null = BC Aconst_null []
getfield x = BC Getfield [x]
putfield x = BC Putfield [x]
invokevirtual x = BC Invokevirtual [x]
invokenonvirtual x = BC Invokenonvirtual [x]

-- helpers
iconst_0 = ldcint 0
iconst_1 = ldcint 1



bmap :: Map Instr Id
bmap = M.fromList [(Nop, "nop")
                  ,(I2c, "i2c")
                  ,(New, "new")
                  ,(Instanceof, "instanceof")
                  ,(Checkcast, "checkcast")
                  ,(Imul, "imul") 
                  ,(Ineg, "ineg")
                  ,(Irem, "irem")
                  ,(Isub, "isub")
                  ,(Idiv, "idiv")
                  ,(Iadd, "iadd")
                  ,(Iinc, "iinc")
                  ,(Label, "label")
                  ,(Goto, "goto")
                  ,(Ifeq, "ifeq")
                  ,(Ifne, "ifne")
                  ,(If_acmpeq, "if_acmpeq")
                  ,(If_acmpne, "if_acmpne")
                  ,(Ifnull, "ifnull")
                  ,(Ifnonnull, "ifnonnull")
                  ,(If_icmpeq, "if_icmpeq")
                  ,(If_icmpgt, "if_icmpgt")
                  ,(If_icmplt, "if_icmplt")
                  ,(If_icmple, "if_icmple")
                  ,(If_icmpge, "if_icmpge")
                  ,(If_icmpne, "if_icmpne")
                  -- is_if
                  ,(Ireturn, "ireturn")
                  ,(Areturn, "areturn")
                  ,(RReturn, "return")
                  ,(Aload, "aload")
                  ,(Astore, "astore")
                  ,(Iload, "iload")
                  ,(Istore, "istore")
                  ,(Dup, "dup")
                  ,(Pop, "pop")
                  ,(Swap, "swap")
                  ,(LdcInt, "ldc_int")
                  ,(LdcString, "ldc_string")
                  ,(Aconst_null, "aconst_null")
                  ,(Getfield, "getfield")
                  ,(Putfield, "putfield")
                  ,(Invokevirtual, "invokevirtual")
                  ,(Invokenonvirtual, "invokenonvirtual")
                  ]

cPred :: Bytecode -> Id
cPred (BC b _) = "is_" ++ bmap!b

make :: Instr -> Id
make b = "makeCODE" ++ bmap!b

{-
v
int is_nop(CODE *c)
int is_i2c(CODE *c)
int is_new(CODE *c, char **arg)
int is_instanceof(CODE *c, char **arg)
int is_checkcast(CODE *c, char **arg)
int is_imul(CODE *c)
int is_ineg(CODE *c)
int is_irem(CODE *c)
int is_isub(CODE *c)
int is_idiv(CODE *c)
int is_iadd(CODE *c)
int is_iinc(CODE *c, int *offset, int *amount)
int is_label(CODE *c, int *label)
int is_goto(CODE *c, int *label)
int is_ifeq(CODE *c, int *label)
int is_ifne(CODE *c, int *label)
int is_if_acmpeq(CODE *c, int *label)
int is_if_acmpne(CODE *c, int *label)
int is_ifnull(CODE *c, int *label)
int is_ifnonnull(CODE *c, int *label)
int is_if_icmpeq(CODE *c, int *label)
int is_if_icmpgt(CODE *c, int *label)
int is_if_icmplt(CODE *c, int *label)
int is_if_icmple(CODE *c, int *label)
int is_if_icmpge(CODE *c, int *label)
int is_if_icmpne(CODE *c, int *label)
^

int is_if(CODE **c, int *label)

v
int is_ireturn(CODE *c)
int is_areturn(CODE *c)
int is_return(CODE *c)
int is_aload(CODE *c, int *arg)
int is_astore(CODE *c, int *arg)
int is_iload(CODE *c, int *arg)
int is_istore(CODE *c, int *arg)
int is_dup(CODE *c)
int is_pop(CODE *c)
int is_swap(CODE *c)
int is_ldc_int(CODE *c, int *arg)
int is_ldc_string(CODE *c, char **arg)
int is_aconst_null(CODE *c)
int is_getfield(CODE *c, char **arg)
int is_putfield(CODE *c, char **arg)
int is_invokevirtual(CODE *c, char **arg)
int is_invokenonvirtual(CODE *c, char **arg)
^

int is_empty(CODE *c)
int is_simplepush(CODE *c)
-}



-- other stuff
data Arg = Str String | IConst Int | SVar Int | IVar Int | CExp [AArg]
           deriving(Show, Eq, Ord)

isVar x = isIVar x || isSVar x


isIVar (IVar _) = True
isIVar _ = False

isIArg (IVar _) = True
isIArg (IConst _) = True
isIArg _ = False

isSVar (SVar _) = True
isSVar _ = False

isSArg (SVar _) = True
isSArg (Str _) = True
isSArg _ = False

data AArg = A Arg | S String
          deriving(Eq, Show, Ord)

-- should only need to do simplifications with int
-- explicitly
instance Num Arg where
    fromInteger x = IConst (fromInteger x)
    (+) = undefined
    (*) = undefined
    abs = undefined
    signum = undefined

data Cond = Indegree Arg Int
          deriving(Eq, Show)

data Pattern = ([Bytecode], [Cond]) :-->: [Bytecode]
             deriving(Show, Eq)

data Pat = Pat String Pattern
         deriving(Show, Eq)
