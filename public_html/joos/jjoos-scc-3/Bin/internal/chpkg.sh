#!/bin/sh
#
# chpkg.sh - modifies package tree root name, reflecting change
#            in the grammar, and affected java files in tree
#          - assumes that package is always followed by '.' or ';'
#
# Note: do not forget to update the other shell scripts, as necessary
#       (and of course move the package tree root directory...)
#       there is no need to recompile the grammar since all SableCC-
#       generated files are also updated
#


FROM=joos
TO=joosc
ROOT=$JOOSDIR/src

update_file() {
	sed -e "s/$FROM\./$TO\./g" -e "s/$FROM\;/$TO\;/g" $1 > $1.chpkg
	rm -f $1; mv $1.chpkg $1;
}

visit() {
	if test -d $1; then return; fi
	case $1 in *.java) update_file $1;; esac
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