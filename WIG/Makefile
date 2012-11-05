CC = gcc

CFLAGS = -Wall -ansi -pedantic

all: 
	make code --no-print-directory

code: y.tab.o lex.yy.o main.o tree.h tree.o pretty.h pretty.o memory.h memory.o weeder.h weeder.o symbol.h symbol.o prettysymbol.h prettysymbol.o type.h type.o prettytype.h prettytype.o
	$(CC) lex.yy.o y.tab.o tree.o pretty.o memory.o main.o weeder.o symbol.o prettysymbol.o type.o prettytype.o -o wig -lfl -lm

check:
	make weed --no-print-directory
	make pretty --no-print-directory

weed:
	./wig failExit.wig 
	./wig failShow.wig
	./wig failDivideByZero.wig
	./wig chess.wig weededchess.wig

pretty:
	./wig smalltest.wig prettysmalltest.wig --noweeder --notypecheck

symbol:
	./wig smalltest.wig --nosymbol --noweeder --nopretty --notypecheck

type:
	./wig smalltest.wig --noweeder --nopretty 

testtype:
	./wig typefailtests/fail1.wig --nopretty
	./wig typefailtests/fail2.wig --nopretty
	./wig typefailtests/fail3.wig --nopretty
	./wig typefailtests/fail4.wig --nopretty
	./wig typefailtests/fail5.wig --nopretty
	./wig typefailtests/fail6.wig --nopretty
	./wig typefailtests/fail7.wig --nopretty
	./wig typefailtests/fail8.wig --nopretty
	./wig typefailtests/fail9.wig --nopretty
	./wig typefailtests/fail10.wig --nopretty
	./wig typefailtests/fail11.wig --nopretty
	./wig typefailtests/fail12.wig --nopretty
	./wig typefailtests/fail13.wig --nopretty
	./wig typefailtests/fail14.wig --nopretty
	./wig typefailtests/fail15.wig --nopretty
	./wig typefailtests/fail16.wig --nopretty
	./wig typefailtests/fail17.wig --nopretty
	./wig typefailtests/fail18.wig --nopretty
	./wig typefailtests/fail19.wig --nopretty
	./wig typefailtests/fail20.wig --nopretty
	./wig typefailtests/fail21.wig --nopretty
	./wig typefailtests/fail22.wig --nopretty
	./wig typefailtests/fail23.wig --nopretty
	./wig typefailtests/fail24.wig --nopretty
	./wig typefailtests/fail25.wig --nopretty

testsymbol:
	./wig failtests/fail1.wig --nopretty --notypecheck
	./wig failtests/fail2.wig --nopretty --notypecheck
	./wig failtests/fail3.wig --nopretty --notypecheck
	./wig failtests/fail4.wig --nopretty --notypecheck
	./wig failtests/fail5.wig --nopretty --notypecheck
	./wig failtests/fail6.wig --nopretty --notypecheck
	./wig failtests/fail7.wig --nopretty --notypecheck
	./wig failtests/fail8.wig --nopretty --notypecheck
	./wig failtests/fail9.wig --nopretty --notypecheck
	./wig failtests/fail10.wig --nopretty --notypecheck
	./wig failtests/fail11.wig --nopretty --notypecheck
	./wig failtests/fail12.wig --nopretty --notypecheck
	./wig failtests/fail13.wig --nopretty --notypecheck
	./wig failtests/fail14.wig --nopretty --notypecheck
	./wig failtests/fail15.wig --nopretty --notypecheck
	./wig failtests/fail16.wig --nopretty --notypecheck
	./wig failtests/fail17.wig --nopretty --notypecheck

y.tab.c y.tab.h: wig.y
	bison --yacc --defines wig.y

lex.yy.c: wig.l y.tab.h
	flex wig.l

clean:
	rm y.tab.* lex.yy.*; rm *.o
	rm wig