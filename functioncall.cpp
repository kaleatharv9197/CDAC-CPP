#include <iostream>
using namespace std;
void add(int no1,int no2)
{
	cout<<"\nAdding integers :"<<no1<<"+"<<no2<<"="<<(no1+no2);
}
void add(float no1,float no2)
{
	cout<<"\nAdding float :"<<no1<<"+"<<no2<<"="<<(no1+no2);
}
void add(int no1,int no2,int no3)
{
	cout<<"\nAdding 3 integers :"<<no1<<"+"<<no2<<"+"<<no3<<"="<<(no1+no2+no3);
}
int main()
{
    add(10,20);
    add(12.40f,11.60f);
    add(12,23,34);
    add(float(10),45.02);
    return 0;
}
