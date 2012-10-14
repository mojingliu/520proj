#!/bin/sh
#
# descent.sh - customizable recursive source tree descent
#


ROOT=$JOOSDIR/src

update_file() {
	cat $JOOSDIR/Bin/internal/license-header.txt $1 > $1.licensed
	rm -f $1; mv $1.licensed $1
}
	
visit() {
	if test -d $1; then return; fi
	case $1 in *.java) update_file $1; esac
}

# 1 param: directory
descent_rec() {
	echo descending $1...
	for f in `ls $1`; do
		visit $1/$f
		if test -d $1/$f; then
			descent_rec $1/$f
		fi
	done
}

update_file $ROOT/joos.sablecc
echo grammar file updated
descent_rec $ROOT
echo source tree updated
echo -n "Clean the classes directory now (recommended)? [y/n] "
read ans
if test $ans = "y"; then
	$JOOSDIR/Bin/clean.sh
fi
