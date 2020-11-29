#include <stdio.h>

void ArrayManipulation(int *array1, int *array2, unsigned length);
void PrintArrays(int *array1, int *array2, unsigned length);

int main(){
	int array1[6] = {2, 3, 4, 5, 6, 7};
	int array2[6] = {8, 9, 10, 11, 12, 13};
	
	ArrayManipulation(array1, array2, 6);
	PrintArrays(array1, array2, 6);
	return 0;
}

void ArrayManipulation(int *array1, int *array2, unsigned length){
	int middle = length/2;
	
	int i = 0;
	for(; i < middle; i++){
		*(array1 + i) = *(array1 + i) ^ *(array2 + i);
		*(array2 + i) = *(array1 + i) ^ *(array2 + i);
		*(array1 + i) = *(array1 + i) ^ *(array2 + i);
	}

	for (; i < length; i++){
		*(array1 + i) *= 3;
		*(array2 + i) += *(array1 + i);
	}
}

void PrintArrays(int *array1, int *array2, unsigned length){
	int i = 0;

	printf("Array1\n");
	for(; i < length; i++){
		printf("%d ", *(array1 + i));
	}
	printf("\n");


	printf("Array2\n");
	for(i = 0; i < length; i++){
		printf("%d ", *(array2 + i));
	}
	printf("\n");
}
