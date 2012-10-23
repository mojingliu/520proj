CC = gcc

CFLAGS = -Wall -ansi -pedantic

all: 
	make code --no-print-directory
	make check --no-print-directory

code: y.tab.o lex.yy.o main.o tree.h tree.o pretty.h pretty.o memory.h memory.o weeder.h weeder.o
	$(CC) lex.yy.o y.tab.o tree.o pretty.o memory.o main.o weeder.o -o wig -lfl -lm

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

y.tab.c y.tab.h: wig.y
	bison --yacc --defines wig.y

lex.yy.c: wig.l y.tab.h
	flex wig.l

clean:
	rm y.tab.* lex.yy.*; rm *.o
	rm wig result