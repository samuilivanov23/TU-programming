#include <stdio.h>

int main()
{
    char c;
    printf("Enter character: ");
    scanf("%c", &c);

    if(c >= '0' && c <= '9')
    {
       printf("digit\n"); 
    }
    else
    {
        printf("Not digit\n");
    }

    return 0;
}