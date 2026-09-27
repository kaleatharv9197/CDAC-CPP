#include <iostream>
using namespace std;

class FE {
protected:
    int rollNo;
    string name;
    int m1, m2, m3;

public:

    void acceptFE() {
        cout << "Enter Roll No: ";
        cin >> rollNo;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter FE Subject 1 Marks: ";
        cin >> m1;

        cout << "Enter FE Subject 2 Marks: ";
        cin >> m2;

        cout << "Enter FE Subject 3 Marks: ";
        cin >> m3;
    }
};

class SE : public FE {
private:
    int s1, s2, s3;
    int total;
    float percentage;
    string remark;

public:

    void acceptSE() {
        cout << "Enter SE Subject 1 Marks: ";
        cin >> s1;

        cout << "Enter SE Subject 2 Marks: ";
        cin >> s2;

        cout << "Enter SE Subject 3 Marks: ";
        cin >> s3;
    }

    void calculate() {

        total = m1 + m2 + m3 + s1 + s2 + s3;

        percentage = total / 6.0;

        if (percentage >= 75)
            remark = "Distinction";
        else if (percentage >= 60)
            remark = "First Class";
        else if (percentage >= 50)
            remark = "Second Class";
        else if (percentage >= 40)
            remark = "Pass";
        else
            remark = "Fail";
    }

    void display() {

        cout << "\n----- Student Details -----" << endl;

        cout << "Roll No       : " << rollNo << endl;
        cout << "Name          : " << name << endl;

        cout << "\nFE Marks:" << endl;
        cout << "Subject 1     : " << m1 << endl;
        cout << "Subject 2     : " << m2 << endl;
        cout << "Subject 3     : " << m3 << endl;

        cout << "\nSE Marks:" << endl;
        cout << "Subject 1     : " << s1 << endl;
        cout << "Subject 2     : " << s2 << endl;
        cout << "Subject 3     : " << s3 << endl;

        cout << "\nTotal Marks   : " << total << endl;
        cout << "Percentage    : " << percentage << "%" << endl;
        cout << "Remark        : " << remark << endl;
    }
};

int main() {

    SE student;

    student.acceptFE();
    student.acceptSE();
    student.calculate();
    student.display();

    return 0;
}