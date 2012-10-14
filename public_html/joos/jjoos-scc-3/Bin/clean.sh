#!/bin/sh
#
# clean.sh - empties the classes directory
#
# usage:  clean.sh
#

echo -n cleaning the classes directory...
for f in `ls $JJOOSDIR/classes`; do
	rm -rf $JJOOSDIR/classes/$f
done
echo " done"
