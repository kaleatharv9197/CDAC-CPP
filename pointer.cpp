#include <iostream>
using namespace std;

class User
{
    string name;
    int age;

public:
    // Constructor
    User(string n, int a)
    {
        name = n;
        age = a;
    }

    // Show function
    void show()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

    // Destructor
    ~User()
    {
        cout << "Destructor called" << endl;
    }
};

int main()
{
    string name;
    int age;

    cout << "Enter name: ";
    cin >> name;

    cout << "Enter age: ";
    cin >> age;

    User u(name, age);

    u.show();

    return 0;
}