#include <iostream>
using namespace std;

int GetMaxNumber( int a, int b, int c );

int main() 
{
    int a,b,c;

    cout << "a= "; cin >> a;
    cout << "b= "; cin >> b;
    cout << "c= "; cin >> c;
    
    cout << "Max number is: " << GetMaxNumber( a, b, c ) << "\n";
    //printf( "Max number is: %d\n", GetMaxNumber( a, b, c ) );

    return 0;
}

int GetMaxNumber( int a, int b, int c )
{
    int max;
    if( a > b )
    {
        max = a;
    }
    else 
    {
        max = b;
    }

    if( c > max )
    {
        max = c;
    }

    return max;
}   
