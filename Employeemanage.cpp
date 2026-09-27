#include <iostream>
using namespace std;

class Employee {
private:
    int id;
    string name;
    double salary;
    int attendedDays;
    double bonus;
    double netSalary;

public:

    void accept() {
        cout << "Enter Employee ID: ";
        cin >> id;

        cout << "Enter Employee Name: ";
        cin >> name;

        cout << "Enter Salary: ";
        cin >> salary;

        cout << "Enter Attended Days: ";
        cin >> attendedDays;
    }

    void calculate() {
        if (attendedDays > 200) {
            bonus = salary * 10 / 100;
        }
        else {
            bonus = salary * 6.5 / 100;
        }

        netSalary = salary + bonus;
    }

    void display() {
        cout << "\n----- Employee Details -----" << endl;
        cout << "Employee ID   : " << id << endl;
        cout << "Employee Name : " << name << endl;
        cout << "Salary        : " << salary << endl;
        cout << "Attended Days : " << attendedDays << endl;
        cout << "Bonus         : " << bonus << endl;
        cout << "Net Salary    : " << netSalary << endl;
    }
};

int main() {

    Employee e;

    e.accept();
    e.calculate();
    e.display();

    return 0;
}