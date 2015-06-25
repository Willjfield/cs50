#include <stdio.h>
#include <cs50.h>

float money;
int cents;
int counter;

void deduct(int c){
	if(c>=25){
		c-=25;
		counter++;
		//printf("%d\n", c);
		deduct(c);
	}else if (c>=10){
		c-=10;
		counter++;
		//printf("%d\n", c);
		deduct(c);
	}else if (c>=5){
		c-=5;
		counter++;
		//printf("%d\n", c);
		deduct(c);
	}else if (c>0){
		c-=1;
		counter++;
		//printf("%d\n", c);
		deduct(c);
	}else{
		//printf("%d\n", c);
		printf("It will take %d coins\n", counter);
	}
}

int main(void)
{
	printf("Enter the amount of money: ");
	money = GetFloat();
	cents = (long)((money*100)+0.5);
	counter = 0;

	deduct(cents);		
}