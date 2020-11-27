%option noyywrap
%{
#include <stdio.h>
#include <string.h>
int k = 0;
FILE *file, *yyin, *temp, *out, *temp2;
char str[20];
char buf[200];

#define SHIFT 10;

%}

%%
	
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

	for (int i = 0; i < strlen(buf); i++){
		buf[i] = buf[i] + SHIFT;
	}

	buf[strlen(buf) - 2] = buf[strlen(buf) - 1] = '\n';
	yylex();
	fprintf(out, "%s", buf);

	fclose(yyin);
	fclose(yyout);
	fclose(out);


}
