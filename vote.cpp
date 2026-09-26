#include <iostream>
using namespace std;

class Person {
public:
    int age;

    void can_vote() {
        if (age >= 18) {
            cout << "Yes, you can vote";
        } else {
            cout << "No, you cannot vote";
        }
    }
};

int main() {
    Person p1;

    cout << "Enter your age: ";
    cin >> p1.age;

    p1.can_vote();

    return 0;
}