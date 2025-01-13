digits [0-9]
DataTypes "INTEGER"|"FLOAT"|"VOID"|"STRING"|"CHARACTER"
Identifier [A-Za-z_][A-Za-z0-9_]*
SingleComment \/\/[^\n]*
MultiComment \/\*([^*]|\*[^\/])*\*\/

%{
	#include "2007031.tab.h"
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	int varindex(char *var);
	extern int yylex();
	extern int yyparse();
	extern FILE *yyin;
	extern FILE *yyout;
	int lineNo = 1;
%}

%%

{SingleComment} { printf("\n>> Single Line Comment Found\n"); }
{MultiComment} { printf("\n>> Multi-line Comment Block Found\n"); }

"INTEGER" { return INT; }
"FLOAT" { return FLOAT; }
"STRING" { return STRING; }
"CHARACTER" { return CHAR; }

"(" { return '('; }
")"	{ return ')'; }
"<" { return '<'; }
">"	{ return '>'; }
"{"	{ return '{'; }
"}"	{ return '}'; }
";" { return END; }
"," { return ','; }
"="	{ return '='; }
":" { return ':'; }

"+"	{ return '+'; }
"-"	{ return '-'; }
"*"	{ return '*'; }
"/"	{ return '/'; }
"^"	{ return '^'; }
"mod" { return MOD; }
"strjoin" { return STRJOIN; }

"less" { return LT; }
"great"	{ return GT; }
"equal"	{ return EQ; }
"great_eq" { return GEQ; }
"less_eq" { return LEQ; }
"not_eq" { return NEQ; }

"++" { return INC; }
"--" { return DEC; }
"!"	{ return NOT; }

"sin" { return SIN; }
"cos" { return COS; }
"tan" { return TAN; }
"ln" { return LN; }
"log" { return LOG; }
"isOddEven" { return ODDEVEN; }
"factorial"	{ return FACTORIAL; }
"max" { return MAX; }
"min" { return MIN; }
"isPrime" { return PRIME; }

"print" { return DISPLAY; }

"if" { return IF; }
"else_if" { return ELSE_IF; }
"else" { return ELSE; }

"for" { return FOR; }
"inc" { return FLINC; }
"dec" { return FLDEC; }
"while" { return WHILE; }

"case" { return CASE; }
"switch" { return SWITCH; }
"default" { return DEFAULT; }

"-"?{digits}+ {
	yylval.string = strdup(yytext);
	return NUMBER;
}

"-"?({digits}+)?"."{digits}+ {
	yylval.string = strdup(yytext);
	return NUMBER;
}

"\""[^"]*"\"" {
	yylval.string = strdup(yytext);
	return STR;
}

{DataTypes}[ ]+"main" { return MAIN; }
"#include" { return IMPORT; }
{Identifier}".h" { return HEADER; }

"function" { return DEF; }

{Identifier} { 
	yylval.string = strdup(yytext);
	return VARIABLE; 
}

[ \t] ;
\n { lineNo++; }

'.' { yylval.string = strdup(yytext); return CHAR_LIT; }

. {}

%%
int yyerror() {
	printf("Error at line %d: %s\n", lineNo + 1, yytext);
}
