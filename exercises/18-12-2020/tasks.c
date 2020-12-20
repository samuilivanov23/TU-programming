#include <stdio.h>

void remove_element(int *oldarr, int * newarr, int pos, unsigned size);
void PrintArrays(int *array1, unsigned length);

int main(){
    // testing lengths
    int oldarr[6] = {2, 3, 4, 5, 6, 7};
	int newarr[5];
    int pos = 2;

    remove_element(oldarr, newarr, pos, 6);
    PrintArrays(oldarr, 6);
    PrintArrays(newarr, 5);
    return 0;
}

void remove_element(int *oldarr, int * newarr, int pos, unsigned size){
    int i = 0;
    int j = 0;

    for(; i < size; i++){
        if(i != pos){
            *(newarr + j) = *(oldarr + i);
            j++;
        }
	}
}

void PrintArrays(int *array, unsigned length){
    int i = 0;

    printf("Array\n");
    for(; i < length; i++){
        printf("%d ", *(array + i));
    }
    printf("\n");
}
