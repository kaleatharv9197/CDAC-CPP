#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int arr[] ={2,1,5,3,4,6,2};

    int k=3; // Fixed window size

    int n=sizeof(arr)/sizeof(arr[0]);

    // Stop when a complete window of size k is not possible
    for (int i=0;i<=n-k;i++)
    {
        vector<int> window;

        for (int j=i;j<i+k;j++)
        {
            window.push_back(arr[j]);
        }

        cout << "\nWindow has: ";

        for (int item : window)
        {
            cout<<item<<",";
        }
    }

    return 0;
}