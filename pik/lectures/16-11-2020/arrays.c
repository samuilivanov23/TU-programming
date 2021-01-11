#include <stdio.h>

int getMinElement(int array[], unsigned len);
int countMinElementOccurances(int array[], unsigned len, int minElement);
int sumElements(int array[], unsigned len);

int main()
{
    int array[] = { 1, 2, 3, 4, 5, 6, 1, 2, 1, 1 ,4, 5, 1 };

    unsigned len = (unsigned)( sizeof(array) / sizeof(array[0]) );

    int minElement = getMinElement(array, len);
    printf("Min element: %d\n", minElement);

    int timesMinElementOccurances = countMinElementOccurances(array, len, minElement);
    printf("times of min element occurances: %d\n", timesMinElementOccurances);

    int sumOfElemetns = sumElements(array, len);
    printf("times of min element occurances: %d\n", sumOfElemetns);
    
    return 0;
}


int getMinElement(int array[], unsigned len)
{
    int i = 1;
    int minElement = array[0];

    for(; i<len; i++)
    {
        if(array[i] < minElement)
        {
            minElement = array[i];
        }
    }

    return minElement;
}

int countMinElementOccurances(int array[], unsigned len, int minElement)
{
    int i = 0;
    int numberOfOccurances = 0;

    for(; i < len; i++)
    {
        if(array[i] == minElement)
        {
            numberOfOccurances++;
        }
    }

    return numberOfOccurances;
}

int sumElements(int array[], unsigned len)
{
    int i = 0;
    int sum = 0;

    for(; i < len; i++)
    {
        sum+=array[i];
    }

    return sum;
}