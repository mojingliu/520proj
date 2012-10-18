CC = gcc

CFLAGS = -Wall -ansi -pedantic

main: y.tab.o lex.yy.o main.o tree.h tree.o pretty.h pretty.o eval.h eval.o memory.h memory.o
	$(CC) lex.yy.o y.tab.o tree.o pretty.o eval.o memory.o main.o -o wig -lfl -lm

y.tab.c y.tab.h: wig.y
	bison --yacc --defines wig.y

lex.yy.c: tiny.l y.tab.h
	flex wig.l
check:
	./check
clean:
	rm y.tab.* lex.yy.*; rm *.o; rm wig result
