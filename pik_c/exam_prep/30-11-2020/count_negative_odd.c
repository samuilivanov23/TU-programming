#include <stdio.h>

int CountNegativeOdd();

int main(){
	int count = CountNegativeOdd();
	printf("sum of negative odd nums: %d\n", count);
	return 0;
}

int CountNegativeOdd(){
	int count = 0;
	int number;

	do{
		scanf("%d", &number);

		if((number != -333) && (number < 0) && (number % 2 != 0)){
			count++;
		}
	}while(number != -333);

	return count;
}
