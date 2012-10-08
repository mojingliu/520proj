#!/bin/sh
#
# compile.sh - compiles the JOOS-J compiler source tree,
#              copies the lexer.dat and parser.dat files
#              needed for execution
#            - JOOS grammar must have been already compiled
#            - JAVADIR, JOOSDIR, SABLECCDIR must be set
#
# usage:  compile.sh [OPTIONS]
#         where OPTIONS are passed to the compiler as is
#
# Note: unfortunately, when the -d option is used,
#       javac always (re)compiles the entire source tree.
#


JAVAC=$JAVADIR/bin/javac
JAVACFLAGS=$*

# compile compiler
cd $JJOOSDIR/src # javac need to run at source root directory
echo -n compiling the source tree...
$JAVAC $JAVACFLAGS -d $JJOOSDIR/classes "joosc/Main.java" 
echo " done"

# copy .dat SableCC files to be used at execution
echo -n copying SableCC-generated lexer.dat and parser.dat files...
cp $JJOOSDIR/src/joosc/lexer/lexer.dat $JJOOSDIR/classes/joosc/lexer/
cp $JJOOSDIR/src/joosc/parser/parser.dat $JJOOSDIR/classes/joosc/parser/
echo " done"

