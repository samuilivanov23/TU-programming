#include <iostream>
#include <math.h>

using namespace std;

class triangle {
    private:
        double a, b, c;
    public:
        triangle();
        double face();
        void show(char *);
        ~triangle()
        {
            cout << "\nDestruncting triangle object";
        }
};

triangle::triangle()
{
    do
    {
        cout << "\n\nEnter three values for the sides of the triangle";
        cin >> a >> b >> c;
    }
    while(!((a>0) && (b>0) && (c>0) && ((a+b>c) && (a+c>b) && (b+c>a))));
}

double triangle::face()
{
    double p, s;
    p=(a+b+c) / 2;
    s=sqrt(p*(p-a)*(p-b)*(p-c));
    return s;
}

void triangle::show(char *name)
{
    cout << "Sides of the triangle " << name << ":\n";
    cout << "a=" << a << ", b=" << b << ", c=" << c;
}


int main()
{
    triangle obj1;
    double s;
    s = obj1.face();
    obj1.show("Triangle111");
    cout << "\nThe face of the triangle is s=" << s;

    return 0;
}
