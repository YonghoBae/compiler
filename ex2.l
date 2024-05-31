%{
#define 	IF	100
#define 	ID	101
#define 	RELOP	102
#define		WHILE 103
#define		FOR	104
#define		SWITCH	105
#define		CASE	106

#define		LE	201
int yylval, tok;
%}
delim		[ \t\n]
ws		{delim}+
letter		[A-Za-z]
digit		[0-9]
id		{letter}({letter}|{digit})*
%%
{ws}	{/* do nothing */}
if		{yylval = 0; return(IF); }
while	{yylval = 0; return(WHILE); }
for		{yylval = 0; return(FOR); }
switch	{yylval = 0; return(SWITCH); }
case	{yylval = 0; return(CASE); }
\/\/[^\n]*	{/* do nothing */}
{id}		{yylval = install_id(); return(ID);}
"<="		{yylval= LE; return(RELOP);}
%%
int install_id() { return(1); }
int yywrap() {return(0);};
main(){ while(1){ tok = yylex(); printf("%d %d\n", tok, yylval);}}
