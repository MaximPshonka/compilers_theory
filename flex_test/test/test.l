%option noyywrap
%{
#include<stdio.h>
#include <string.h>
int k = 0;
FILE *file, *yyin, *temp, *out, *temp2;
char str[20];
char buf[200];
int global_counter = 0;
int local_counter = 0;
int anon_counter = 0;
%}

%%
@@[a-z]+([a-z]|[0-9])+:  	{fprintf(yyout," ");anon_counter++;}
[a-z]+([a-z]|[0-9])+:		{fprintf(yyout," ");global_counter++;}
\.[a-z]+([a-z]|[0-9])+:		{fprintf(yyout," ");local_counter++;}
%%


void main(){
	file = fopen("work/input.txt", "r");
	while (!feof(file)) {
		fscanf(file, "%s", str);
		strcat(buf, str);
		strcat(buf, "  ");
	}
	temp = fopen("temp.txt", "w");
	fprintf(temp, "%s", buf);
	fclose(temp);
	fclose(file);

	yyin = fopen("temp.txt", "r");
	yyout = fopen("temp2.txt", "w");
	out = fopen("work/output.txt", "w");

	yylex();
	fprintf(out, "global - %d, anon - %d, local - %d", global_counter, anon_counter, local_counter);

	fclose(yyin);
	fclose(yyout);
	fclose(out);


}
