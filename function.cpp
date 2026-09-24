#include<iostream>
using namespace std;
void my_function()//type 1
{
	cout<<"\n\t\thi i am my function: called by you";
}
void my_function2(string n)//type 2
{
	cout<<"\n\t\thi, "<<n;
}
string copyright()//type 3
{
	return "Code created by Atharv Kale. ";
}
string initials(string first_name,string last_name)//type 4
{
	string init="";
	init+=first_name[0];
	init+=last_name[0];
	return init;
}
int main()
{
	cout<<"\nStart in the main part. ";
	cout<<"\nSome code, some logic. ";
	my_function();
	my_function2("Atharv");
	cout<<"\n\t\tInfo:"<<copyright();
	cout<<"\n\t\tAtharv Kale initials:"<<initials("atharv","kale");
	cout<<"\nEnd in main part";
   return 0;
}
