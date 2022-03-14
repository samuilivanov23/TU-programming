#include <stdio.h>

unsigned char swapBits(unsigned char c) 
{ 
    unsigned char even_bits = c & 0xAAAAAAAA;
    unsigned char odd_bits = c & 0x55555555;

    even_bits >>= 1; 
    odd_bits <<= 1; 

    return (even_bits | odd_bits);
} 

int main() 
{
    unsigned char c;
    printf("Enter character: ");
    scanf("%c", &c);
    
    printf("%u \n", swapBits(c));

    return 0; 
}