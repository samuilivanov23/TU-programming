#include <stdio.h>

void block_diagram (int n, int arr[]);

int main(){
	return 0;
}

void block_diagram (int n, int arr[]){
	int ft = 1;

	for(;;){
		if(ft){
			ft = 0;
			int i = 1;

			for(;;){
				if(i < n){
					//arr swap TODO

					if(arr[i] < arr[i-1]){
						int temp = arr[i];
						arr[i] = arr[i - 1];
						arr[i - 1] = temp;

						ft = 1;
					}	

					i = 1;
				}
			}
			
		}
		else{
			break;
		}
	}
}