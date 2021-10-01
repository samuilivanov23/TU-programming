#include<stdio.h>
#include <math.h>

#define EPS 1e-5

double sinx(double x);

int main()
{
    double x;
    printf("Enter x: ");
    scanf("%lf", &x);
    printf("result: %.10f\n", sinx(x)); // 10 floating point numbers
    return 0;
}

double sinx(double x)
{  
    double xrad = x/180*M_PI;
    double sum = xrad;
    double ch = xrad;
    double prevch;
    int sign = -1;
    double number = 3;
    
    do
    {
        prevch = ch;
        ch *= xrad*xrad/(number * (number - 1));
        sum += ch*sign;
        sign *= -1;
        number += 2;
    }
    while(fabs(ch - prevch) >= EPS);

    return sum;
}