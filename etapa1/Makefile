
EXEC_FILE = etapa1
SOURCE_FILES = $(wildcard *.c)
OBJECT_FILES = lex.yy.o $(patsubst %.c, %.o, $(SOURCE_FILES))

all: $(EXEC_FILE)
	@echo "source: $(SOURCE_FILES)"
	@echo "obj: $(OBJECT_FILES)"

$(EXEC_FILE): $(OBJECT_FILES)
	gcc $(OBJECT_FILES) -o $@

lex.yy.c lex.yy.h: scanner.l
	lex --header-file=lex.yy.h $<

%.o: %.c
	gcc -c $<

clean:
	rm -f $(wildcard *.o) $(EXEC_FILE) *~ lex.yy.c lex.yy.h lex.yy.h.gch *.tgz
