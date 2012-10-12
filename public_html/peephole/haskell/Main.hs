module Main where

import Patterns
import PatternC
import Types
import C

import System.IO

import Text.PrettyPrint.Leijen


main :: IO ()
main = do
  let x = displayS . renderPretty 0.6 80 . vsep
          . punctuate line $ map doIT patterns ++ [pretty (makeInit patterns)] ++ [line]
  writeFile "gen_patterns.h" (x "")
  
makeAdd :: Pat -> Stmt
makeAdd (Pat n _) = ExprStmt $ Inv "ADD_PATTERN" [Ident n]

makeInit :: [Pat] -> Fn
makeInit = Fn VoidT "init_gen_pats" [] . map makeAdd