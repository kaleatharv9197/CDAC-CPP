#include <iostream>
using namespace std;

template <typename T>
class Box
{
  	 T value;

public:
    void setValue(T v)
    {
        value = v;
    }

    void display()
    {
        cout << "Value = " << value << endl;
    }
};

int main()
{
    Box<int> b1;
    b1.setValue(100);
    b1.display();

    Box<float> b2;
    b2.setValue(25.5f);
    b2.display();

    return 0;
}