#!/bin/sh
#
# java1tojava2.sh - removes references to ca.mcgill.sable.util package
#                   to allow compilation and use of compiler under Java 2 Platform
#                 - assumes that JAVADIR points to JDK 1.2 or higher, and that
#                   SABLECCDIR points to SableCC 2.10 or higher


ROOT=${JJOOSDIR}/src

update_file() {
	if grep -q "import java\.util\.\*;" $1; then
		sed -e "s/import ca\.mcgill\.sable\.util\.\*\;//g" $1 > $1.java1tojava2
		rm -f $1; mv $1.java1tojava2 $1;
	else
		sed -e "s/import ca\.mcgill\.sable\.util\.\*\;/import java\.util\.\*\;/g" $1 > $1.java1tojava2
		rm -f $1; mv $1.java1tojava2 $1;
	fi
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


echo -n "WARNING! This operation is not reversible. Are you sure you want to proceed? [y/n] "
read ans
if test $ans != "y"; then
	exit 127
fi
echo "deleting obsolete framework code..."
rm -rf $ROOT/joosc/node $ROOT/joosc/analysis $ROOT/joosc/parser $ROOT/joosc/lexer
echo " done"
echo "converting compiler code..."
descent_rec $ROOT
echo "source tree updated"
echo -n "Recompile the grammar now (recommended)? [y/n] "
read ans
if test $ans = "y"; then
	$JJOOSDIR/Bin/compilegrammar.sh
fi
echo -n "Clean the classes directory now (recommended)? [y/n] "
read ans
if test $ans = "y"; then
	$JJOOSDIR/Bin/clean.sh
fi
echo -n "Recompile the compiler source tree now (recommended)? [y/n] "
read ans
if test $ans = "y"; then
	$JJOOSDIR/Bin/compile.sh
fi
echo "Congratulations! The compiler installation is now Java2-ready."
