#include <iostream>
using namespace std;

// Base Class
class A
{
	public:
	A()
	{
		cout<<"\nA here";
	}
};
class B:public A
{
	public:
	B()
	{
		cout<<"\nB : i am here";
	}
};

class C:public B
{
	public:
	C()
	{
		cout<<"\nC : yes i m done";
	}
};

int main()
{
    C obj;

    return 0;
} 