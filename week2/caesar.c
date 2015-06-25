#include <cs50.h>
#include <stdio.h>
#include <strings.h>

int main(int argc, string argv[])
{
	if(argc != 2){
    	return 1;
    }

    int k = atoi(argv[1]);
    string s = GetString();

    for (int i = 0; i < strlen(s); i++)
    {
    	if(s[i]>='A'&&s[i]<='Z'){
    		s[i]=(s[i]-'A'+k)%('Z'-'A'+1);
    		s[i]+='A';
    	}else if(s[i]>='a'&&s[i]<='z'){
    		s[i]=(s[i]-'a'+k)%('z'-'a'+1);
    		s[i]+='a';
    	}else if(s[i]>='0'&&s[i]<='9'){
    		s[i]=(s[i]-'0'+k)%('9'-'0'+1);
    		s[i]+='0';
    	}
    }

    printf("%s\n", s);
    printf("%d\n", argc);
}