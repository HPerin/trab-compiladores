FLAGS = -g

all:	etapa4

etapa4: lex.yy.o main.o hash.o y.tab.o ast.o generator.o semantic.o
	gcc $(FLAGS) -o etapa4 lex.yy.o main.o hash.o y.tab.o ast.o generator.o semantic.o

main.o: main.c lex.yy.c
	gcc $(FLAGS) -c main.c

hash.o: hash.c
	gcc $(FLAGS) -c hash.c

ast.o: ast.c
	gcc $(FLAGS) -c ast.c

generator.o: generator.c
	gcc $(FLAGS) -c generator.c

semantic.o: semantic.c
	gcc $(FLAGS) -c semantic.c

lex.yy.o: lex.yy.c
	gcc $(FLAGS) -c lex.yy.c

lex.yy.c: scanner.l y.tab.o
	lex --header-file=lex.yy.h scanner.l

y.tab.o: y.tab.c
	gcc $(FLAGS) -c y.tab.c

y.tab.c: parser.y
	yacc -d parser.y

clean:
	rm -f lex.yy.c lex.yy.h y.tab.c y.tab.h *.o etapa4

