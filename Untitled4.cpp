#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n = 5;

    for(int i = 1; i <= n; i++)
    {
        cout << setfill('*') << setw(i) << "" << endl;
    }

    return 0;
}