#include <stdio.h>
#include <limits.h>

int FindMaxEven(int *array, unsigned length);
int Max(int a, int b);
float Average(int *array, unsigned length);
int Sum(int *array, unsigned length);
void PrintArray(int *array, unsigned length);
void Swap2Elements(int *array, int index1, int index2);


int main(){
	int array[5];

	int i = 0;
	
	//array initialization
	for(; i < 5; i++){
		printf("%d: ", i+1);
		scanf("%d", &array[i]);
	}
	
	int max_even = FindMaxEven(array, 5);
	float average = Average(array, 5);
	int sum = Sum(array, 5);

	printf("max even: %d\n", max_even);
	printf("average: %.2f\n", average);
	printf("sum: %d\n", sum);
	PrintArray(array, 5);

	int index1, index2;
	printf("Enter first index to swap: ");
	scanf("%d", &index1);

	printf("Enter second index to swap: ");
	scanf("%d", &index2);	

	Swap2Elements(array, index1, index2);
	PrintArray(array, 5);

	return 0;
}

int FindMaxEven(int *array, unsigned length){

	int max = INT_MIN;
	char has_even = 0;	

	int i = 0;
	for(; i < length; i++){

		if(*(array + i) % 2 == 0){
			max = Max(max, *(array + i));
			has_even = 1;
		}
	}

	if(has_even){
		return max;
	}
	else{
		return 0;
	}

	return 1;
}

float Average(int *array, unsigned length){
	int i = 0;
	int sum = 0;

	for(; i < length; i++){
		sum += *(array + i);		
	}

	float average = (float)sum/length;
	return average;
}

int Sum(int *array, unsigned length){
	int sum = 0;

	int i =0;	
	for(; i < length; i++){
		sum += *(array + i);		
	}
	
	return sum;
}

void PrintArray(int *array, unsigned length){
	int i =0;
	for(; i < length; i++){
		printf("%d ", *(array + i));
	}
	printf("\n");
}

void Swap2Elements(int *array, int index1, int index2){
	*(array + index1) = *(array + index1) ^ *(array + index2);
	*(array + index2) = *(array + index1) ^ *(array + index2);
	*(array + index1) = *(array + index1) ^ *(array + index2);
}

int Max(int a, int b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}
