#include <iostream>
using namespace std;

// Parent / Base class
class Parent
{
public:
    virtual void show()
    {
        cout << "Parent class show()" << endl;
    }
};

// Child / Derived class
class Child : public Parent
{
public:
    void show() override
    {
        cout << "Child class show()" << endl;
    }
};

int main()
{
    Parent *ptr;     // Parent pointer
    Child child;     // Child object

    ptr = &child;    // Parent pointer points to Child object

    ptr->show();

    return 0;
}