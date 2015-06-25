#include <stdio.h>
#include <cs50.h>

int rows;

int main(void)
{
	printf("enter number of rows between 1 and 23: ");
	rows = GetInt();

	if(rows<1 || rows>24){
		printf("%s\n", "That was not between 1 and 23. Try again.");
		main();		
	}else{
		for(int i=1;i<=rows;i++){
			for(int k=rows-i;k>0;k--){
				printf("%s"," ");
			}
			for(int j=0;j<i;j++){
				printf("#");
			}
			printf("\n");	
		}
	}
}