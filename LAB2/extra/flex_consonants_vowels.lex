%{
int vowel=0, cons=0;
%}
%%
[Aa|Ee|Ii|Oo|Uu] {vowel++;}
[A-Za-z] {cons++;}

%%
int yywrap(){} 
int main()
{
printf("Hey there! welcome to my vowels and consonant program\n");
printf("Please enter a string e.g Jules:");
yylex();
printf("consonants are: %d\n",cons);
printf("vowels are: %d\n",vowel);
system("pause");
return 0;
}
