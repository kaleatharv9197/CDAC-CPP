#include <iostream>
#include <cstring>
using namespace std;

void concat(char (&str)[100], char (&str1)[100], char (&str3)[200])
{
    strcpy(str3, str);
    strcat(str3, str1);
}

int main()
{
    char str[100], str1[100], str3[200];

    cout << "Enter first string: ";
    cin.getline(str, 100);

    cout << "Enter second string: ";
    cin.getline(str1, 100);

    concat(str, str1, str3);

    cout << "Third string: " << str3 << endl;

    return 0;
}