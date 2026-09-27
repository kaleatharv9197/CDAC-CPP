
#include <iostream>
using namespace std;
/*
friend function:
It is a special type of function which is declared within a class defined outside the class. 

We use `friend` as a keyword before its prototype. 

It is defined independently outside the class. 

Access private, protected, and public data of a class like a member. 

One should remember that to a friend you will send an object and then it can access. Direct access not possible 

A friend can be a friend of multiple classes, allowing inter-class calculation and communication. 

*/
class Human
{
private:
    string name;
public:
 Human(string name)
    
    {
        this->name = name;
     	cout<<"\nA human called "<<this->name<<" is created.";
    }
  
	friend void secrate_hai(Human h);//Current function is declared as a friend to the current class. 
};

void secrate_hai(Human h)//Definition of friend function
{
	cout<<"\n Done by friend of Human: object has secrate name:"<<h.name;
}

int main()
{
	Human h("tatyawinchu");
	Human h2("chota bheem");
	secrate_hai(h);//A friend function is called independently without any object because it is not part of anyone. 
	secrate_hai(h2);//A friend function is called independently without any object because it is not part of anyone. 
    return 0;
}




