#!/bin/sh
#
# descent.sh - customizable recursive source tree descent
#


ROOT=$JOOSDIR/src

visit() {
# TODO: make copy of this file and fill this function
	echo `basename $1`
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

descent_rec $ROOT
