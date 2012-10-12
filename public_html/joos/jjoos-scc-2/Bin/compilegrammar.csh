#!/bin/csh
#
# compilegrammar.csh - generates framework code by running 
#                     SableCC on our JOOS grammar
#                   - JAVADIR, JJOOSDIR, SABLECCDIR must be set
#
# usage:  compilegrammar.csh
#

$JAVADIR/bin/java -mx512m -jar $SABLECCDIR/lib/sablecc.jar $JJOOSDIR/src/joos.sablecc 
