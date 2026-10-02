#include <iostream>
#include <cstring>
using namespace std;

void copyString(char (&str)[100], char (&str1)[100])
{
    strcpy(str1, str);
}

int main()
{
    char str[100], str1[100];

    cout << "Enter a string: ";
    cin.getline(str, 100);
    copyString(str, str1);
    cout << "Original string: " << str << endl;
    cout << "Copied string: " << str1 << endl;

    return 0;
}