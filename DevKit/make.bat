win_flex --wincompat -o %1lex.c %1.l
win_bison -d -o %1.c %1.y
gcc %1.c %1lex.c -o %1