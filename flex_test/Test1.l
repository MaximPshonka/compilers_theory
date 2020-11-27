%option noyywrap
%{
int global_counter = 0;
int local_counter = 0;
int anon_counter = 0;
%}

%%

^@@[a-z]+([a-z]|[0-9])+:  	anon_counter++;
^[a-z]+([a-z]|[0-9])+:		global_counter++;
^\.[a-z]+([a-z]|[0-9])+:	local_counter++;



%%


void main(){
	yylex();
	printf("global - %d, anon - %d, local - %d", global_counter, anon_counter, local_counter);
	
}
