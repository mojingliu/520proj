module C where

import Data.Generics
import Text.PrettyPrint.Leijen

-- Indentation amount.
ind_amt :: Int
ind_amt = 2

data Fn = Fn Type Id [Param] [Stmt]
        deriving(Show, Eq)

instance Pretty Fn where
    pretty (Fn t i ps ss) =
        pretty t <+> pretty i <> parens (pretty ps) <+> pretty (Block ss)

data Type = IntT | VoidT | CharT | X String | Ptr Type
          deriving(Show, Eq)

instance Pretty Type where
    pretty IntT = text "int"
    pretty VoidT = text "void"
    pretty CharT = text "char"
    pretty (X t) = text t
    pretty (Ptr x) = pretty x <> text "*"

type Id = String

data Param = Param Type Id
           deriving(Show, Eq)

instance Pretty Param where
    pretty (Param t i) = pretty t <+> pretty i
    prettyList = align . sep . punctuate comma . map pretty

-- simple statment data type, to be expanded as needed
data Stmt = Ifte Pred Stmt Stmt
          | Ift Pred Stmt
          | Return Exp
          | ExprStmt Exp
          | Decl Type [Dtype]
          | Block [Stmt]
          deriving(Show, Eq)

data Dtype = Bare Id | Arry Id Int
             deriving(Show, Eq)
                     
instance Pretty Dtype where
    pretty (Bare x) = pretty x
    pretty (Arry x n) = pretty x <> brackets (pretty n)

instance Pretty Stmt where
    pretty (Ifte p c a) =
        text "if" <> parens (pretty p) <+> pretty (pretty c) <+> text "else" <+> pretty a
    pretty (Ift p c) =
        text "if" <> parens (pretty p) <+> pretty c
    pretty (Return e) = text "return" <+> pretty e <> semi
    pretty (ExprStmt e) = pretty e <> semi
    pretty (Decl t is) = pretty t <+> (sep . punctuate comma . map pretty) is <> semi
    pretty (Block ss) = braces (line <> indent ind_amt (align . vsep $ map pretty ss) <> line)

-- Unless there will be "or" I'll jsut stick with this
data Pred = Conj [Exp]
          deriving(Show, Eq)

instance Pretty Pred where
    pretty (Conj es) = align . sep . punctuate (empty <+> text "&&") $ map pretty es


-- Simple expression data type, to be expanded as needed
data Exp = Inv Id [Exp]
         | Int Int
         | St String
         | Ident Id
         | Star Exp
         | Addr Exp
         | Arr Id Exp
         | Eql Exp Exp
         | Lte Exp Exp
         | Field Exp Id
         | PExp String
         deriving(Show, Eq)

-- Pretty printing the expressions
instance Pretty Exp where
    pretty (Inv i es) = pretty i <> parens (pretty es)
    pretty (Int i) = pretty i
    pretty (St s) = dquotes $ pretty s
    pretty (Ident i) = pretty i
    pretty (Star e) = pretty "*" <> parens (pretty e)
    pretty (Addr e) = pretty "&" <> parens (pretty e)
    pretty (Arr n i) = pretty n <> brackets (pretty i)
    pretty (Eql e1 e2) = pretty e1 <+> pretty "==" <+> pretty e2
    pretty (Lte e1 e2) = pretty e1 <+> pretty "<=" <+> pretty e2
    pretty (Field e n) = pretty e <> dot <> pretty n
    pretty (PExp s) = pretty s
    prettyList = align . sep . punctuate comma . map pretty

-- Num instance makes life a bit easier
instance Num Exp where
    fromInteger = Int . fromInteger
    (+) = undefined
    (*) = undefined
    abs = undefined
    signum = undefined