%{
 #include "syntax.tab.h"
 int yycolumn = 1;
 #define YY_USER_ACTION \
	yylloc.first_line = yylloc.last_line = yylineno; \
	yylloc.first_column = yycolumn; \
	yylloc.last_column = yycolumn + yyleng - 1; \
	yycolumn += yyleng;
 extern char IdString[300];
%}
digit [0-9]
letter [a-zA-Z]
relop ">"|"<"|">="|"<="|"=="|"!="
blank [" ""\t"]+
int {digit}+
float {int}\.{digit}+
id ["_"]?{letter}+({letter}|{digit})*
%option yylineno
%%
{int} {
	yylval.type_int = atoi(yytext);
	return INT;
}
{float} { 
	yylval.type_float = atof(yytext);
	return FLOAT; 
}
(int|float)/{blank} {
	yylval.type_char = yytext;
	return TYPE;
}
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return STAR;}
"/" {return DIV;}
"&&" {return AND;}
"||" {return OR;}
"." {return DOT;}
"!" {return NOT;}
"(" {return LP;}
")" {return RP;}
"[" {return LB;}
"]" {return RB;}
"{" {return LC;}
"}" {return RC;}
struct/{blank} {return STRUCT;}
return/{blank} {return RETURN;}
if/({blank}|"(") {return IF;}
else/({blank}|"{") {return ELSE;}
while/({blank}|"(") {return WHILE;}
";" {return SEMI;}
"," {return COMMA;}
"=" {return ASSIGNOP;}
{relop} {return RELOP;}
{id} {
	strcpy(IdString, yytext);
	return ID;
}
"//" {
	char c = input();
	while (c != '\n') c = input();
	printf("//\n");
	return CM;
}
"/*" {
	char a = input();//"/"
	char b = input();//"*'
	do{
		a = b;
		b = input();
	}while(!(a=='*'&&b=='/'));
	printf("/*\n");
	return LCM;
}
"*/" {return RCM;}
{blank} {}
\n { yycolumn = 1; }
. {
  printf("Error type A at line %d: Mysterious characters \'%s\'\n", yylineno, yytext);
  }
%%
