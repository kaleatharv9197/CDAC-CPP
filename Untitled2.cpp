#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Step 1: Create and write into the file
    ofstream outFile("me.txt");

    if (!outFile)
    {
        cout << "Error creating file!" << endl;
        return 1;
    }

    outFile << "<Name>" << endl;
    outFile << "Atharv Deepak Kale" << endl;
  

    outFile << "<Email>" << endl;
    outFile << "kaleatharv@gmail.com" << endl;
   
    outFile << "<Phone>" << endl;
    outFile << "8605305628" << endl;
  

    outFile.close();

    // Step 2: Read the file using ifstream
    ifstream inFile("me.txt");

    if (!inFile)
    {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string line;

    cout << "----- File Content -----" << endl;

    while (getline(inFile, line))
    {
        cout << line << endl;
    }

    inFile.close();

    return 0;
}