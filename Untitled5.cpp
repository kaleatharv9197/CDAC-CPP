#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n = 5;
 		cout << "*";
    for(int i = 1; i <= n; i++){
        if(i == 1){
           
        }
        else if(i == n) {
            cout << setfill('*') << setw(i) << "";
        }
        else{
            cout << "*";
            cout << setw(i - 1) << setfill(' ') << "*";
        }

        cout << endl;
    }

    return 0;
}