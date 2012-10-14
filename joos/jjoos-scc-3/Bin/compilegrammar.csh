#!/bin/csh
#
# compilegrammar.csh - generates framework code by running 
#                     SableCC on our JOOS grammar
#                   - JAVADIR, JJOOSDIR, SABLECCDIR must be set
#
# usage:  compilegrammar.csh
#

setenv CLASSPATH .:$SABLECCDIR/sablecc.jar:
$JAVADIR/bin/java -mx1024m SableCC $JJOOSDIR/src/joos.sablecc 
