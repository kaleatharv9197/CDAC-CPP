#include <iostream>
using namespace std;

class Human
{
	private:
    int age;
    string name,gender;

public:
    void set_human(string name,string gender,int age)
    {
     	this->name=name;
     	this->gender=gender;
     	this->age=age;
        cout<<"\nAll data set .";
    }

    void display_human()
    {
        cout << "\nI am "<<name<<", a "<<gender<<" and age is "<<age;
    }
};

int main()
{
    
  Human h;
  h.set_human("heman","male",36);
  h.display_human();
  
    return 0;
}
