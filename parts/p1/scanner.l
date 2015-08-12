%{

#include "hash.h"

hash_map_t * hash_map;

int current_line = 0;
int running = 1;

%}

%%

"if"        { }
[a-zA-Z]+   { hash_map_insert(hash_map, yytext); }
"\n"        { current_line++; }
.           { }

%%

int yywrap() {
    running = 0;
    return 1;
}

int isRunning (void) {
    return running;
}

int getLineNumber(void) {
    return current_line;
}

#include "main.c"
