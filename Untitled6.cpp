#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n = 5;

    for(int i = n; i >= 1; i--){
        int spaces = n - i;
        int stars = 2 * i - 1;

        if(i == n){
            cout << setw(spaces + stars) << setfill('*') << "" << endl;
        }
        else if(i == 1) {
            cout << setw(spaces + 1) << setfill(' ') << "*" << endl;
        }
        elses {
            cout << setw(spaces + 1) << setfill(' ') << "*";
            cout << setw(stars - 1) << setfill(' ') << "*";
            cout << endl;
        }
    }

    return 0;
}