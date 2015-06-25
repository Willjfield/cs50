#include <cs50.h>
#include <stdio.h>
#include <strings.h>
#include <ctype.h>

//counter will see how many non A-Z or a-z characters are used and skip them
int counter;

int main(int argc, string argv[])
{
	counter = 0;

	if(argc != 2){
    	return 1;
    }
    //get argument
    string k = argv[1];
    //convert to all upper
    for(int i = 0; i < strlen(k);i++){
    	toupper(k[i]);
    }
    //prompt for string
    string s = GetString();

    for (int i = 0; i < strlen(s); i++)
    {
    	//get non alpha characters
    	if(!isalpha(s[i])){
    		counter++;
    	}

    	if(s[i]>='A'&&s[i]<='Z'){
    		int offset = k[(i-counter)%strlen(k)]-'a';
    		s[i]=(s[i]-'A'+offset)%('Z'-'A'+1);
    		s[i]+='A';
    		printf("offset for %c matches %c and should equal %d\n", s[i],k[i],offset);
    	}else if(s[i]>='a'&&s[i]<='z'){
    		int offset = k[(i-counter)%strlen(k)]-'a';
    		s[i]=(s[i]-'a'+offset)%('z'-'a'+1);
    		s[i]+='a';
    		printf("offset for %c matches %c and should equal %d\n", s[i],k[i],offset);
    	}
    }
    printf("%s\n", s);
}