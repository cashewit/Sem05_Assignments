%option noyywrap

%{
#include<stdio.h>
#include<strings.h>
void func(char*);
%}

%%
^(\").*(\")$ func(yytext);

^(\').*(\')$ func(yytext);

.* {printf("Invalid String");}
%%

int main(){
yylex();
return 0;
}

void func(char* a){
	int n = strlen(a);
	a[n-1] = '\0';
	printf("String: %s\n", a+1);
}
