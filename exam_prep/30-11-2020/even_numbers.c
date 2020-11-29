#include <stdio.h>

int * SumCountEven();

int main(){
	int * arr;
	
	arr = SumCountEven();
	printf("Sum: %d\n", *(arr));
	printf("Count: %d\n", *(arr + 1));

	return 0;
}

int * SumCountEven(){
	int count = 0;
	int sum = 0;

	int number;

	do{
		printf("number: ");
		scanf("%d", &number);

		if(!(feof(stdin)) && ((number % 2) == 0)){
			sum += number;
			count++;		
		}

	}while(!feof(stdin));

	static int arr[2];

	arr[0] = sum; //set the sum
	arr[1] = count; //set the count

	return arr; //return the tuple as array
}
