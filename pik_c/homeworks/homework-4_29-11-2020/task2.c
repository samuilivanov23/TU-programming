#include <stdio.h>
#include <ctype.h>

void PrintCharArray(char *char_array, unsigned length);
int IsVowel(char char1);


int main(){
	
	char array[3] = {'h', 'u', 'i'};

	PrintCharArray(array, 3);
	return 0;
}

void PrintCharArray(char *char_array, unsigned length){
	int i = length;
	
	for(; i >= 0; i--){
		if(IsVowel(*(char_array + i))){
			//Print upercase vowel char
			printf("%c\n", toupper(*(char_array + i)));
		}
		else{
			//Print lowercase char
			printf("%c\n", tolower(*(char_array + i)));
		}
	}
}

int IsVowel(char char1){
	if(char1 == 'a' || char1 == 'A'){
		return 1;
	}
	else if(char1 == 'e' || char1 == 'E'){
		return 1;
	}
	else if(char1 == 'i' || char1 == 'I'){
		return 1;
	}
	else if(char1 == 'o' || char1 == 'O'){
		return 1;
	}
	else if(char1 == 'u' || char1 == 'U'){
		return 1;
	}
	else{
		return 0;
	}
}
