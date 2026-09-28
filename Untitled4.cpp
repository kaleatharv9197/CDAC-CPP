#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string name, email, phone;

    // Take details from user
    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your email: ";
    getline(cin, email);

    cout << "Enter your phone number: ";
    getline(cin, phone);

    // Create and open file
    //ofstream fwrite(name+".txt");
    ofstream fwrite("mydata.txt",ios::app);
    //Enables append mode of the file. If the file is not there it will create and add data. 
    //If the file is already there it will go to the end of the file and start writing from there. 
    // Write data into file
    if(!fwrite.is_open())//if Not open. 
    	{
    		cout<<"\nSome kind of error in opening file ";
    		return 1;//stop code
		}
    fwrite << "Name: " << name << endl;
    fwrite << "Email: " << email << endl;
    fwrite << "Phone: " << phone << endl;

    // Close file
    fwrite.close();

    cout << "\nData written successfully and file closed.";

    return 0;
}
