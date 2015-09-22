%{

#include "hash.h"
#include "y.tab.h"



hash_map_t * hash_map;

int current_line = 1;
int running = 1;


%}

%x COMMENT

%%

[ \t]                                       { }
"int"                                       { return KW_INT; }
"real"                                      { return KW_REAL; }
"bool"                                      { return KW_BOOL; }
"char"                                      { return KW_CHAR; }
"if"                                        { return KW_IF; }
"else"                                      { return KW_ELSE; }
"loop"                                      { return KW_LOOP; }
"input"                                     { return KW_INPUT; }
"output"                                    { return KW_OUTPUT; }
"return"                                    { return KW_RETURN; }
"/*"                                        { BEGIN COMMENT; }
"//".*                                      { }
[\-\,\;\:\(\)\{\}\[\]\+\*\/\<\>\=\!\&\$]      { return yytext[0]; }
"<="                                        { return OPERATOR_LE; }
">="                                        { return OPERATOR_GE; }
"=="                                        { return OPERATOR_EQ; }
"!="                                        { return OPERATOR_NE; }
"&&"                                        { return OPERATOR_AND; }
"||"                                        { return OPERATOR_OR; }
"FALSE"                                     { return LIT_FALSE; }
"TRUE"                                      { return LIT_TRUE; }
'[a-zA-Z]'                                  { hash_map_insert(hash_map, LIT_CHAR, yytext); yylval.symbol = hash_map_search(hash_map, yytext); return LIT_CHAR; }
\"[^\"]*\"                                  { hash_map_insert(hash_map, LIT_STRING, yytext); yylval.symbol = hash_map_search(hash_map, yytext); return LIT_STRING; }
[0-9]+					    { hash_map_insert(hash_map, LIT_INTEGER, yytext); yylval.symbol = hash_map_search(hash_map, yytext); return LIT_INTEGER; }
[a-zA-Z][_a-zA-Z]*                          { hash_map_insert(hash_map, TK_IDENTIFIER, yytext); yylval.symbol = hash_map_search(hash_map, yytext); return TK_IDENTIFIER; }
"\n"                                        { current_line++; }

<COMMENT>"\n"                               { current_line++; }
<COMMENT>"*/"                               { BEGIN INITIAL; }
<COMMENT>" \t"                              { }
<COMMENT>.

.                               { return TOKEN_ERROR; }

%%

int yywrap() {
    running = 0;
    hash_map_print(hash_map);
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
