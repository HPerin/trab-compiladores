
EXEC_FILE = etapa1
SOURCE_FILES = $(wildcard *.c)
OBJECT_FILES = $(patsubst %.c, %.o, $(SOURCE_FILES))

all: $(EXEC_FILE)

$(EXEC_FILE): $(OBJECT_FILES)
	gcc $< -o $@

%.o: %.c
	gcc -c $<

lex.yy.c: scanner.l
	lex $<

clean:
	rm $(wildcard *.o) $(EXEC_FILE) *~
