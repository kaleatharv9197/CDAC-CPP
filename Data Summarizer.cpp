#include <iostream>
#include <fstream>
#include <ctype.h>
using namespace std;

int main()
{
    ifstream file("india.txt");
    if (!file){
        cout << "Error: Unable to open india.txt"<<endl;
        return 1;
    }
    char ch;
    int lines = 0;
    int words = 0;
    int alphabets = 0;
    int digits = 0;
    int spaces = 0;
    int symbols = 0;
    bool inWord = false;
    // Read file character by character
    while (file.get(ch)){
        // Count alphabets
        if (isalpha(ch)){
            alphabets++;
        }
        // Count digits
        else if (isdigit(ch)){
            digits++;
        }
        // Count whitespace
        if (isspace(ch)){
            spaces++;
            // Newline means one line
            if (ch == '\n'){
                lines++;
            }
            // End of a word
            inWord = false;
        }
        else{
            // Start of a new word
            if (!inWord){
                words++;
                inWord = true;
            }
        }
        // Count special symbols
        if (!isalpha(ch) && !isdigit(ch) && !isspace(ch)){
            symbols++;
        }
    }
    file.close();
    cout << "\n !!!!!DATA SUMMARY REPORT!!!!!" << endl;
    cout << "Total Lines          : " << lines << endl;
    cout << "Total Words          : " << words << endl;
    cout << "Total Alphabets      : " << alphabets << endl;
    cout << "Total Digits         : " << digits << endl;
    cout << "Total Spaces         : " << spaces << endl;
    cout << "Total Special Symbols: " << symbols << endl;
    cout << "=========================================" << endl;
    return 0;
}