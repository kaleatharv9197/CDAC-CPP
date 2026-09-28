#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fr("india.txt");
  	string line;
    if(!fr.is_open())//if Not open. 
    	{
    		cout<<"\nSome kind of error in opening file ";
    		return 1;//stop code
		}
  	//Read a file. 
  	//We can use a single character,: .get()
	//a single word.: >>
  	//a single line: getline(fr,)
  	int count=1;
  	while(getline(fr,line))//Stops when the blank occurs. 
  	{
  		cout<<endl<<"Line "<<count++<<"--->"<<line;
  	}
  	
  	
    // Close file
    fr.close();

    cout << "\nData written successfully and file closed.";

    return 0;
}
