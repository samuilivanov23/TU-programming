#include <stdio.h>

int CountDivision7();

int main(){
	int count;
	count = CountDivision7();
	printf("count: %d\n", count);
	return 0;
}

int CountDivision7(){
	int number;
	int count = 0; 

	do{
		scanf("%d", &number);
		if((number != 222) && (number % 7 == 0)){
			count++;	
		}
	}while(number != 222);

	return count;
}


