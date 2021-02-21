#include <stdio.h>

int main(){
    printf("%i\n", EOF);
    float arr[1000];
    int count = 0;
    while(1){
        if(scanf("%f", &arr[count]) == EOF){
            break;
        }
        count++;
    }

    printf("%d\n", count);
    printf("%f %f %f\n", arr[0], arr[1], arr[2]);
    return 0;
}