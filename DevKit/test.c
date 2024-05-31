#include<stdio.h>

int main(){
    char* s = "a\'";
    char ch;
    ch = (char)s[0];
    printf("%s\n",s);
    printf("%d\n",s);
    printf("%d",ch);
}