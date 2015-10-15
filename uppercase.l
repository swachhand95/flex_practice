%{
void to_upper(char* str);
%}

%%

[a-z]*  { to_upper(yytext); printf("%s", yytext); }
.       ECHO;

%%

void to_upper(char* str)
{
    for (int i = 0; str[i] != 0; ++i)
        str[i] -= 32;
}
