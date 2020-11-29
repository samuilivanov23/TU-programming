#include <stdio.h>

int Average ();
int IsSimple(int number);

int main(){
	double average_result = Average();
	printf("result average: %.2f\n", average_result);
	return 0;
}

int Average(){
	int sum = 0;
	int numbers_count = 0;

	int n;
	do{
		scanf("%d", &n);
		if(n != 0){
			printf("is %d simple: %d\n", n, IsSimple(n));
			if(IsSimple(n)){
				sum += n;
				numbers_count++;
			}
		}
		
		
	} while(n != 0);
	
	double average = (double)sum/numbers_count;

	return average;
}

int IsSimple(int number){
	int divisor = 2; //starting division loop from 2

	while(divisor < number){
		if((number % divisor) == 0){
			return 0; //=> number is not simple
		}

		divisor++;
	}

	return 1;
}
