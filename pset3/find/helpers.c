/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */

bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
 	int low = 0;
	int high = n; 
	int mid;  

	do
	{
		mid = (low+high)/2;
		if(value<values[mid]){
			high = mid - 1;
			printf("try lower\n");
		} else if (value>values[mid]){
			low = mid + 1;
			printf("try higher\n");
		}
	} while (value != values[mid] && low <=high);

	if(value == values[mid]){
		printf("found it in the %d position\n", mid);
		return 1;
	}else{
		return 0;
	}
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    for(int i=0; i<n-1;i++){  
		for(int j=i+1;j<n;j++){
			if(values[j]<values[i]){
				int temp = values[i];
				values[i]=values[j];
				values[j]=temp;
			}
		} 	
    }
    for(int i=0; i<n;i++){    
    	printf("%d\n", values[i]);
	}
    return;
}
