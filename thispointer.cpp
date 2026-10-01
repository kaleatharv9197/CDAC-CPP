
#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
    int age;
    char name[20];
   

public:
    Person(int age, const char name[]) {
        strcpy(this->name, name);
        this->age = age;
       
    }

    void show() {
        cout << "\nName = " << name << "\nAge = " << age;
    }
    //fuction return object
    Person maxAge(Person &obj){
    if(age>obj.age)
    return *this;
    else
    return(obj);
}

    ~Person() {
        cout << "\n Object destroyed";
    }
};

int main() {
    Person p1(23, "Atharv");
   
Person p2(22,"sk");
Person p(0,"\0");
p=p1.maxAge(p2);
cout<<"\nElder parson";
p.show();
    return 0;
}