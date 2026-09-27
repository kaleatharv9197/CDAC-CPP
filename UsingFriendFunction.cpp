#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    int inches;

public:

    Distance(int f, int i)
    {
        feet = f;
        inches = i;
    }

    friend Distance operator+(Distance, Distance);

    void display()
    {
        cout << feet << " Feet "
             << inches << " Inches";
    }
};

Distance operator+(Distance d1, Distance d2)
{
    Distance temp(0, 0);

    temp.feet = d1.feet + d2.feet;
    temp.inches = d1.inches + d2.inches;

    if(temp.inches >= 12)
    {
        temp.feet++;
        temp.inches -= 12;
    }

    return temp;
}

int main()
{
    Distance d1(5, 8);
    Distance d2(3, 7);

    Distance d3 = d1 + d2;

    d3.display();

    return 0;
}
