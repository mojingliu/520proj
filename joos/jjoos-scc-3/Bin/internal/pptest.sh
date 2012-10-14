#!/bin/sh
#
# Uses the AST pretty-printer to verify the equation
# pretty-print(pretty-print(input)) = pretty-print(input).
#  4 Jun 2000 - recast to new set of wrapper scripts in Bin
#  2 Jun 2000 - now uses the compiler wrapper script ./joos
#  1 Apr 2000 - supports compartmentalized testing, uses new Compiler options, added 'Progs' benchmarks
#  9 Mar 2000 - added Winter99 Benchmarks
#  5 Mar 2000 - created
#set -x
#set -n

# booleans for what to process
FALL99=0
WINTER99=0
PROGS=0

BENCHDIR=$JOOSDIR/Testing/Benchmarks
MODULE_DIR=${1:?} # gripe if first arg not provided
PP_OUT=pp.out
PPPP_OUT=pppp.out
DIR_PATH=$JOOSDIR/Testing/$MODULE_DIR
OPTIONS="--pretty-print"
JOOSC=$JOOSDIR/Bin/joos

# create module testing directory if does not exist
if test ! -e $DIR_PATH; then
	mkdir $DIR_PATH
	echo $DIR_PATH directory created
fi

# argument list parsing
shift # skip first arg
while [ $# -ge 1 ]; do
            case $1 in
            --fall99)    FALL99=1;;
            --winter99)  WINTER99=1;;
            --progs)     PROGS=1;;
            --all)       FALL99=1;WINTER99=1;PROGS=1;;
            *)           echo Unrecognized option: $1;
                         echo "Options: --fall99, --winter99, --progs, --all"; exit 1;;
            esac
            shift
     done

if test ! $FALL99 -eq 0; then

echo ===================
echo FALL99 BENCHMARKS
echo ===================

for i in 01 02 03 04 05 06 07 09 10
do
	echo BENCHMARK $i
	for j in `ls $BENCHDIR/Fall99/${i}Benchmark/*.j[oa]*[sa]`
	do
		echo -n file $j...
		$JOOSC $OPTIONS $j > $DIR_PATH/$PP_OUT
		$JOOSC $OPTIONS $DIR_PATH/$PP_OUT > $DIR_PATH/$PPPP_OUT
		diff $DIR_PATH/$PP_OUT $DIR_PATH/$PPPP_OUT > /dev/null
		if test ! $? -eq 0; then
			echo ' diff: problem'
		else
			echo ' no diff: OK'
		fi
	done
done

fi

if test ! $WINTER99 -eq 0; then

echo ===================
echo WINTER99 BENCHMARKS
echo ===================

for i in 01 02 03 04 05 06 07 08 09 10 11 12 13
do
	echo BENCHMARK $i
	for j in `ls $BENCHDIR/Winter99/${i}/*.j[oa]*[sa]`
	do
		echo -n file $j...
		$JOOSC $OPTIONS $j > $DIR_PATH/$PP_OUT
		$JOOSC $OPTIONS $DIR_PATH/$PP_OUT > $DIR_PATH/$PPPP_OUT
		diff $DIR_PATH/$PP_OUT $DIR_PATH/$PPPP_OUT > /dev/null
		if test ! $? -eq 0; then
			echo ' diff: problem'
		else
			echo ' no diff: OK'
		fi
	done
done

fi

if test ! $PROGS -eq 0; then

echo ================
echo PROGS BENCHMARKS
echo ================

# skip file index.html
for i in `ls -I index.html $BENCHDIR/Progs/`
do
   echo PROG $i
	for j in `ls $BENCHDIR/Progs/${i}/*.j[oa]*[sa]`
	do
		echo -n file $j...
		$JOOSC $OPTIONS $j > $DIR_PATH/$PP_OUT
		$JOOSC $OPTIONS $DIR_PATH/$PP_OUT > $DIR_PATH/$PPPP_OUT
		diff $DIR_PATH/$PP_OUT $DIR_PATH/$PPPP_OUT > /dev/null
		if test ! $? -eq 0; then
			echo ' diff: problem'
		else
			echo ' no diff: OK'
		fi
	done
done

fi

