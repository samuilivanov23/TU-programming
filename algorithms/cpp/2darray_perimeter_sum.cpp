#include <iostream>
using namespace std;

int main() 
{
    int rows = 3;
    int cols = 3;
    int numbers[rows][cols] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int sum = 0;
    
    for ( int row = 0; row < rows; row++ )
    {
        if ( row == 0 )
        {
            for ( int col = 0 ; col < cols; col++ )
            {
                sum += numbers[row][col];
            }
        }
        else if ( row == rows - 1 )
        {
            for ( int col = 0 ; col < cols; col++ )
            {
                sum += numbers[row][col];   
            }
        }
        else
        {
            sum += numbers[row][0] + numbers[row][cols-1];   
        }
    }

    cout << "Sum: " << sum << "\n";
    return 0;
}
