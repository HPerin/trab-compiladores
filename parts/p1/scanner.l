%{

#include "hash.h"
#include "tokens.h"

hash_map_t * hash_map;

int current_line = 0;
int running = 1;

%}

%%

"int"                           { return KW_INT; }
"real"                          { return KW_REAL; }
"bool"                          { return KW_BOOL; }
"char"                          { return KW_CHAR; }
"if"                            { return KW_IF; }
"else"                          { return KW_ELSE; }
"loop"                          { return KW_LOOP; }
"input"                         { return KW_INPUT; }
"output"                        { return KW_OUTPUT; }
"return"                        { return KW_RETURN; }

[,;:(){}[]+-*/<>=!&$]           { return yytext[0]; }
"<="                            { return OPERATOR_LE; }
">="                            { return OPERATOR_GE; }
"=="                            { return OPERATOR_EQ; }
"!="                            { return OPERATOR_NE; }
"&&"                            { return OPERATOR_AND; }
"||"                            { return OPERATOR_OR; }

[a-zA-Z][_a-zA-Z]+              { hash_map_insert(hash_map, yytext); }
"\n"                            { current_line++; }
.                               { }

%%

int yywrap() {
    running = 0;
    return 1;
}

void initMe(void) {
	hash_map = hash_map_new();
}

int isRunning (void) {
    return running;
}

int getLineNumber(void) {
    return current_line;
}
