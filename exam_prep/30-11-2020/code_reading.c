#include <stdio.h>

void function(int a, int b);

int main(){
	
	int a,b,i,k;
	float f;
	char c = 'b';
	
	a = 4;
	b = 0xB;
	printf("1: %d\n", b-a); // 1 : 7 (hex B is 11 in decimal) or 11 - 4 = 7

	function(4,4); // 2 : False because 4 > 5 returns false

	printf("3: %d %d\n", a, b);

	if(a=5){
		printf("4: True\n"); // 4 : True because a=5 expression returns 5 which is != 0
	}
	else{
		printf("4: False\n"); 
	}

	for(i = 1; i < --b; i*=2){
		printf("5: %d\n", i); // 5 : 1, 2, 4
	}

	f = (a%2)*(b/2);
	printf("6: %d %f\n", i, f); // 6: 8 3.00... (f = 1 * 3) b/2 <=> 7/2 

	printf("7: %d\n", a&b);  // 7 : 5 **bitwise AND => 111 & 101 returns 101 (5 in decimal)
	printf("8: %d\n", a||b); // 8 : 1 **logical OR => returns 1 because a != 0 (a=5)

	return 0;
}


void function(int a, int b){

	if(a++ > ++b){
		printf("2: True\n");
	}
	else{
		printf("2: False\n");
	}
}
