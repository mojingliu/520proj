module Patterns where

import Types
import Args
import PatternC

--Baselines
--A+: 18330
--JC: 16790
patterns =
    [--No patterns
     --A-: 23554
     Pat "dup_pop" (([dup, pop],[]) :-->: [])
    ,Pat "imul2" (([ldcint x, ldcint 2, imul],[]) :-->: [ldcint x, dup, iadd])
    ]
