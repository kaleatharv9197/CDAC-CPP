#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
void findMinMax(T a, T b)
{
    cout << "Minimum = " << min(a, b) << endl;
    cout << "Maximum = " << max(a, b) << endl;
}

int main()
{
    findMinMax(10, 20);
    findMinMax(10.5, 5.5);

    return 0;
}