#!/bin/sh
#
#  4 Jun 2000 - recast to using the new wrapper Bin scripts
#  2 Jun 2000 - now uses ./joos script for JOOS compilation
# 13 May 2000 - now compiles joos files in program directory as well; stand-alone extern compile removed
# 12 May 2000 - modified for whole-program compilation (required by symbol table)
#  1 Apr 2000 - supports compartmentalized testing, uses new Compiler options, added 'Progs' benchmarks
#  9 Mar 2000 - added Winter99 Benchmarks
#  5 Mar 2000 - created (Fall99 Benchmarks)
# Batch compiles all benchmarks in verbose mode.
#


# booleans for what to process
FALL99=0
WINTER99=0
PROGS=0

BENCHDIR=$JOOSDIR/Testing/Benchmarks
MODULE_DIR=${1:?} # gripe if first arg not provided
OUT=compile.out
DIR_PATH=$JOOSDIR/Testing/$MODULE_DIR
EXTERN_PATH=Extern
OPTIONS="--verbose"
JOOSC=$JOOSDIR/Bin/joosc

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

echo =================
echo FALL99 BENCHMARKS
echo =================

echo -n processing Benchmark 02...
cat > $DIR_PATH/$OUT << EOF
============
BENCHMARK 02
------------
EOF
$JOOSC $OPTIONS $BENCHDIR/Fall99-dev/02Benchmark/*.j[oa]*[sa] >> \
$DIR_PATH/$OUT
echo ' done'

for i in 03 04 05 06 07 09 10
do
	echo -n processing Benchmark $i...
	cat >> $DIR_PATH/$OUT << EOF
============
BENCHMARK $i
------------
EOF
	$JOOSC $OPTIONS $BENCHDIR/Fall99-dev/${i}Benchmark/*.j[oa]*[sa] >> \
	$DIR_PATH/$OUT
	echo ' done'
done

fi

if test ! $WINTER99 -eq 0; then

echo ===================
echo WINTER99 BENCHMARKS
echo ===================

for i in 02 03 04 05 06 07 08 09 10 11
do
	echo -n processing Benchmark $i...
	cat >> $DIR_PATH/$OUT << EOF
============
BENCHMARK $i
------------
EOF
	$JOOSC $OPTIONS $BENCHDIR/Winter99-dev/$i/*.j[oa]*[sa] >> \
	$DIR_PATH/$OUT
	echo ' done'
done

fi

if test ! $PROGS -eq 0; then

echo ================
echo PROGS BENCHMARKS
echo ================

# skip index.html
for i in `ls -I index.html $BENCHDIR/Progs-dev/`
do
	echo -n processing Prog $i...
	cat >> $DIR_PATH/$OUT << EOF
============
PROG $i
------------
EOF
	$JOOSC $OPTIONS $BENCHDIR/Progs-dev/${i}/*.j[oa]*[sa] >> \
	$DIR_PATH/$OUT
	echo ' done'
done

fi
