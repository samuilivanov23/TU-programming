#include <iostream>
#include "math.h"

using namespace std;

int main()
{
  float a, b, c, p, A, B, C;

  cout << "c = ";
  cin >> c;

  cout << "A = ";
  cin >> A;

  cout << "B = ";
  cin >> B;

  C = 180 - A - B;
  b = c*sin( B )/sin( A );
  a = c*sin( A )/sin( B );

  p = a + b + c;
  
  cout << "p = " << p << "\n";

  return 0;
}
