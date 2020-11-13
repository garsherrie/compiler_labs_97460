%%
[;]+ printf("\n %s : shows end of file \n\n",yytext);
[a-zA-z]+ printf("\n %s : identifier \n\n",yytext);
[0-9]+ {printf("%s : constant.\n\n", yytext); } 
[\\*|\\+|=|\\/|\\%|-] {printf("%s : operator.\n\n", yytext);}


[\n] return 0;
%%

int yywrap(){} 
int main(){ 

	printf("\n Welcome to my simple lexical analyzer with flex");
	printf("\nPlease input your string say (y=24+k;) :");

	
	yylex(); 
	system("pause");
	return 0; 
} 