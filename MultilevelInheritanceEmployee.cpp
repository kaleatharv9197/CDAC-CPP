#include <iostream>
#include <string>
using namespace std;

// Base Class
class Human{
private:
    string name;
    string gender;

public:
    Human(string n, string g){
        name = n;
        gender = g;
    }

    string getName(){
        return name;
    }

    string getGender(){
        return gender;
    }
};
// Derived Class
class Student : public Human{
private: 
string degree;

public:
    Student(string n, string g, string d)
        : Human(n, g){
        degree = d;
    }
    string getDegree(){
        return degree;
    }
};
// Derived Class
class Employee : public Student{
private:
    int employeeId;
    double salary;
public:
    Employee(string n, string g, string d, int id, double s)
        : Student(n, g, d){
        employeeId = id;
        salary = s;
    }
    void display(){
        cout << "\n----- Employee Details -----" << endl;
        cout << "Name       : " << getName() << endl;
        cout << "Gender     : " << getGender() << endl;
        cout << "Degree     : " << getDegree() << endl;
        cout << "Employee ID: " << employeeId << endl;
        cout << "Salary     : " << salary << endl;
    }
};
int main(){
    Employee e("Atharv Kale", "Male", "B.Tech CSE", 101, 45000);

    e.display();

    return 0;
}