#include <iostream>
using namespace std;

// Parent class
class Animal
{
public:
    void eat()
    {
        cout << "Animal is eating" << endl;
    }
};

// Child class
class Dog : public Animal
{
public:
    void bark()
    {
        cout << "Dog is barking" << endl;
    }
};

int main()
{
    Dog d;

    d.eat();   // inherited from Animal
    d.bark();  // Dog's own function

    return 0;
}