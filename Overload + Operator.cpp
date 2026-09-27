#include <iostream>
using namespace std;

class Number
{
private:
    int value;

public:

    Number(int v = 0)
    {
        value = v;
    }

    // Operator overloading
    Number operator+(Number n)
    {
        Number temp;

        temp.value = value + n.value;

        return temp;
    }

    void display()
    {
        cout << "Value: " << value << endl;
    }
};

int main()
{
    Number n1(10);
    Number n2(20);

    Number n3 = n1 + n2;   // + operator overloaded

    n3.display();

    return 0;
}