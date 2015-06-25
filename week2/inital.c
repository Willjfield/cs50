#include <cs50.h>
#include <stdio.h>
#include <strings.h>

int main(void)
{
    string s = GetString();

    for (int i = 0; i < strlen(s); i++)
    {
        if(s[i]>='a'){
        	s[i]-=('a'-'A');
        }
    }
    printf("%s\n", s);
}