#include <stdio.h>

int main()
{
    char c;
    printf("Enter character: ");
    scanf("%c", &c);

    if(c == 'a')
    {
       printf("vowel\n"); 
    }
    else if (c == 'e')
    {
       printf("vowel\n"); 
    }
    else if (c == 'i')
    {
       printf("vowel\n"); 
    }
    else if (c == 'o')
    {
       printf("vowel\n"); 
    }
    else if (c == 'u')
    {
       printf("vowel\n"); 
    }
    else
    {
        printf("not vowel\n");
    }

    return 0;
}