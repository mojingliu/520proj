#!/bin/sh
#
# Counts JOOS compiler source size:
#    LINES: raw code line count
#    LOC: lines of code, i.e. blank and comment-only lines excluded
#


FILES="joos.sablecc joosc/*.java joosc/abstracter/*.java joosc/fixer/*.java joosc/weeder/*.java joosc/symbol/*.java joosc/type/*.java joosc/resource/*.java joosc/code/*.java joosc/code/bytecode/*.java"

cd ${JOOSDIR}/src
echo LINES:
wc -l $FILES
echo LOC:
loc $FILES
