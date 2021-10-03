#include <stdio.h> //1
#include <stdlib.h>
#define TRUE 1

int* readFromFile(char *fname, unsigned *len)
{
	FILE *fin; // 2
	int * array = NULL;
	int temp;
	unsigned count = 0;

	*len = 0;
	fin = fopen(fname, "r"); // 3
	if (fin == NULL){ // 4
		perror(NULL);
		return array;
	}

	// while (!feof(fin)){
	while (TRUE) {
		if (fscanf(fin, "%d", &temp) != 1){ // 5
			if (feof(fin))
				break;
			perror(NULL);
			*len = count;
			return array;
		}

		array = (int*)realloc(array,++count);
		if (array == NULL){
			perror(NULL);
			return array;
		}
		
        array[count-1] = temp;
	}
	fclose(fin); // 6
	*len = count;
	return array;
}

void printArray(int* array,unsigned len)
{
	int i;

	for(i=0;i<len;++i){
		printf("%d ",array[i]);
	}
	printf("\n");
}

unsigned countElements(char *fname)
{
	FILE *fin;
	unsigned size=0;
	int temp;

	if((fin=fopen(fname,"r"))==NULL){
		perror(NULL);
		return size;
	}

	while(TRUE){
		if (fscanf(fin,"%d",&temp)!=1){
			if (feof(fin))
				break;
			perror(NULL);
			return 0;
		}
		size++;
	}
	fclose(fin);
	return size;
}

unsigned readArray(char *fname, int *data, unsigned len)
{
	FILE *fin;
	unsigned i;

	if ((fin=fopen(fname,"r"))==NULL){
		perror(NULL);
		return i;
	}

	for (i=0;i<len;++i){
		if (fscanf(fin,"%d",&data[i])!=1){
			perror(NULL);
			break;
		}
	}

	fclose(fin);
	return i;
}

int main()
{
	int *data;
	unsigned len;
    
    // printf("Hello World!\n");
	// data = readFromFile("integers.txt",&len);
	
    data = readFromFile("files/array_input.txt",&len);
	if (data!=NULL){
		printArray(data,len);
		free(data);
		data = NULL;
	}
	len = countElements("integers.txt");
	// printf("len=%d\n",len);
	if (len){
		int array[len];
		len = readArray("integers.txt",array,len);
		printArray(array,len);
	}
	return EXIT_SUCCESS;
}