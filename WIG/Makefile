CC = gcc

CFLAGS = -Wall -ansi -pedantic

all: 
	make code --no-print-directory
	make check --no-print-directory

code: y.tab.o lex.yy.o main.o tree.h tree.o pretty.h pretty.o memory.h memory.o weeder.h weeder.o symbol.h symbol.o prettysymbol.h prettysymbol.o
	$(CC) lex.yy.o y.tab.o tree.o pretty.o memory.o main.o weeder.o symbol.o prettysymbol.o -o wig -lfl -lm

check:
	make weed --no-print-directory
	make pretty --no-print-directory

weed:
	./wig failExit.wig
	./wig failShow.wig
	./wig failDivideByZero.wig
	./wig chess.wig weededchess.wig

pretty:
	./wig smalltest.wig prettysmalltest.wig --noweeder

symbol:
	./wig smalltest.wig --symbol --noweeder --nopretty

testsymbol:
	./wig failtests/fail1.wig --symbol --nopretty
	./wig failtests/fail2.wig --symbol --nopretty
	./wig failtests/fail3.wig --symbol --nopretty
	./wig failtests/fail4.wig --symbol --nopretty
	./wig failtests/fail5.wig --symbol --nopretty
	./wig failtests/fail6.wig --symbol --nopretty
	./wig failtests/fail7.wig --symbol --nopretty
	./wig failtests/fail8.wig --symbol --nopretty
	./wig failtests/fail9.wig --symbol --nopretty
	./wig failtests/fail10.wig --symbol --nopretty
	./wig failtests/fail11.wig --symbol --nopretty
	./wig failtests/fail12.wig --symbol --nopretty
	./wig failtests/fail13.wig --symbol --nopretty
	./wig failtests/fail14.wig --symbol --nopretty
	./wig failtests/fail15.wig --symbol --nopretty
	./wig failtests/fail16.wig --symbol --nopretty
	./wig failtests/fail17.wig --symbol --nopretty

y.tab.c y.tab.h: wig.y
	bison --yacc --defines wig.y

lex.yy.c: wig.l y.tab.h
	flex wig.l

clean:
	rm y.tab.* lex.yy.*; rm *.o
	rm wig