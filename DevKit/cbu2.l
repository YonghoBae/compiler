%{
#include <string.h>
#include "cbu2.h"
#define MAXSYM	100
#define	MAXSYMLEN	20

char symtbl[MAXSYM][MAXSYMLEN];
int lineno=1;
int insertsym();
int maxsym=0;
char s[MAXSYMLEN];
char str[100];
int temp;
int len;

%}
sp		[ \t]
ws		{sp}+
nl		\n
eletter	[A-Za-z]
hletter	[\xb0-\xfe][\xa0-\xfe]
letter	({eletter}|{hletter})
digit	[0-9]
id		{letter}({letter}|{digit})*
char	\'{letter}\'

%%
{ws}	{/* do nothing */}
{nl}	{lineno++; }
더하기	{return(ADD); }
빼기	{return(SUB); }
곱하기	{return(MUL); }
나누기	{return(DIV); }
나머지	{return(MOD); }
그리고	{return(AND); }
또는	{return(OR); }
문자출력	{return(PRINTCH); }
숫자출력	{return(PRINTNUM); }
입력	{return(INPUT); }
var		{return(VAR); }
if		{return(IF); }
then	{return(THEN); }
else	{return(ELSE); }
while	{return(WHILE); }
continue {return(CONTINUE); }
break	{return(BREAK); }
"<"		{return(LT); }
">"		{return(GT); }
"<="	{return(LE); }
">="	{return(GE); }
"{"		{return('{'); }
"}"		{return('}'); }
"("		{return('('); }
")"		{return(')'); }
"["		{return('['); }
"]"		{return(']'); }
==		{return(EQ); }
!=		{return(NE); }
"+="	{return(ADDASSGN); }
"-="	{return(SUBASSGN); }
"*="	{return(MULASSGN); }
"/="	{return(DIVASSGN); }
:=		{return(ASSGN); }
;		{return(STMTEND); }
시작	{return(START); }
끝		 {return(END); }
{char}	{temp=insertsym(yytext); yylval=MakeNode(CHAR, temp); return(CHAR); }
{id}	{temp=insertsym(yytext); yylval=MakeNode(ID, temp); return(ID);}
{digit}+		{sscanf(yytext, "%d", &temp); yylval=MakeNode(NUM, temp); return(NUM);}
.		{printf("invalid token %s\n", yytext); }
%%

int insertsym(s)
char *s;
{
int i;
	for(i=0;i<maxsym; i++) {
		if(strcmp(s, symtbl[i])==0) return(i);
		}
	if (i<MAXSYM-1) {
		strcpy(symtbl[maxsym],s);
		maxsym++;
		return(maxsym-1);
		}
	else
		{printf("symbol table overflow\n");}
	return(0);
}

yywrap() {}