
EXEC_FILE = etapa1
SOURCE_FILES = $(wildcard *.c)
OBJECT_FILES = $(patsubst %.c, %.o, $(SOURCE_FILES))

all: $(EXEC_FILE)
	@echo "source: $(SOURCE_FILES)"
	@echo "obj: $(OBJECT_FILES)"

$(EXEC_FILE): lex.yy.h $(OBJECT_FILES)
	gcc $(OBJECT_FILES) -o $@

lex.yy.c lex.yy.h: scanner.l
	lex --header-file=lex.yy.h $<

%.o: %.c lex.yy.h
	gcc -c $<

clean:
	rm $(wildcard *.o) $(EXEC_FILE) *~
