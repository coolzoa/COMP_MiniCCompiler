all: programa3 run

run: programa3
	./programa3 prueba.c

lex.yy.c: ccode.l
	lex ccode.l

y.tab.c: ccode.y
	yacc ccode.y -d

programa3: y.tab.c lex.yy.c
	gcc -o programa3 y.tab.c -lfl

clean:
	rm programa3 lex.yy.c y.tab.c y.tab.h

.PHONY: clean all run
