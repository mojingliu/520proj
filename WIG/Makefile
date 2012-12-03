CC = gcc

CFLAGS = -Wall -ansi -pedantic

all: 
	make code --no-print-directory

code: y.tab.o lex.yy.o main.o tree.h tree.o pretty.h pretty.o memory.h memory.o weeder.h weeder.o symbol.h symbol.o prettysymbol.h prettysymbol.o type.h type.o prettytype.h prettytype.o code.h code.o
	$(CC) lex.yy.o y.tab.o tree.o pretty.o memory.o main.o weeder.o symbol.o prettysymbol.o type.o prettytype.o code.o -o douglas -lfl -lm

check:
	make weed --no-print-directory
	make pretty --no-print-directory

weed:
	./douglas failExit.wig --notypcheck --nopretty --nosymbol
	./douglas failShow.wig --notypcheck --nopretty --nosymbol
	./douglas failDivideByZero.wig --notypcheck --nopretty --nosymbol
	./douglas chess.wig --notypcheck --nopretty --nosymbol

pretty:
	./douglas chat.wig prettysmalltest.wig --noweeder --notypecheck --nosymbol

symbol:
	./douglas chat.wig --noweeder --nopretty --notypecheck --printsymbol

type:
	./douglas chat.wig --noweeder --nopretty --prettytype
	./douglas emailer.wig --noweeder --nopretty 
	./douglas fatchecker.wig --noweeder --nopretty

testtype:
	./douglas typefailtests/fail1.wig --nopretty 
	./douglas typefailtests/fail2.wig --nopretty
	./douglas typefailtests/fail3.wig --nopretty
	./douglas typefailtests/fail4.wig --nopretty
	./douglas typefailtests/fail5.wig --nopretty
	./douglas typefailtests/fail6.wig --nopretty
	./douglas typefailtests/fail7.wig --nopretty
	./douglas typefailtests/fail8.wig --nopretty
	./douglas typefailtests/fail9.wig --nopretty
	./douglas typefailtests/fail10.wig --nopretty
	./douglas typefailtests/fail11.wig --nopretty
	./douglas typefailtests/fail12.wig --nopretty
	./douglas typefailtests/fail13.wig --nopretty
	./douglas typefailtests/fail14.wig --nopretty
	./douglas typefailtests/fail15.wig --nopretty
	./douglas typefailtests/fail16.wig --nopretty
	./douglas typefailtests/fail17.wig --nopretty
	./douglas typefailtests/fail18.wig --nopretty
	./douglas typefailtests/fail19.wig --nopretty
	./douglas typefailtests/fail20.wig --nopretty
	./douglas typefailtests/fail21.wig --nopretty
	./douglas typefailtests/fail22.wig --nopretty
	./douglas typefailtests/fail23.wig --nopretty
	./douglas typefailtests/fail24.wig --nopretty
	./douglas typefailtests/fail25.wig --nopretty

testsymbol:
	./douglas failtests/fail1.wig --nopretty --notypecheck
	./douglas failtests/fail2.wig --nopretty --notypecheck
	./douglas failtests/fail3.wig --nopretty --notypecheck
	./douglas failtests/fail4.wig --nopretty --notypecheck
	./douglas failtests/fail5.wig --nopretty --notypecheck
	./douglas failtests/fail6.wig --nopretty --notypecheck
	./douglas failtests/fail7.wig --nopretty --notypecheck
	./douglas failtests/fail8.wig --nopretty --notypecheck
	./douglas failtests/fail9.wig --nopretty --notypecheck
	./douglas failtests/fail10.wig --nopretty --notypecheck
	./douglas failtests/fail11.wig --nopretty --notypecheck
	./douglas failtests/fail12.wig --nopretty --notypecheck
	./douglas failtests/fail13.wig --nopretty --notypecheck
	./douglas failtests/fail14.wig --nopretty --notypecheck
	./douglas failtests/fail15.wig --nopretty --notypecheck
	./douglas failtests/fail16.wig --nopretty --notypecheck
	./douglas failtests/fail17.wig --nopretty --notypecheck

y.tab.c y.tab.h: wig.y
	bison --yacc --defines wig.y

lex.yy.c: wig.l y.tab.h
	flex wig.l

clean:
	rm y.tab.* lex.yy.*; rm *.o
	rm douglas