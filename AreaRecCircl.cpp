#include <iostream>
using namespace std;


void area(double radius)
{
    double result = 3.14 * radius * radius;
    cout << "Area of Circle: " << result << endl;
}

void area(double length, double breadth)
{
    double result = length * breadth;
    cout << "Area of Rectangle: " << result << endl;
}

int main()
{
    area(5);          // Calls area(double radius)

    area(10, 20);     // Calls area(double length, double breadth)

    return 0;
}