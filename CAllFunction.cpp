#include <iostream>
using namespace std;
//In pass-by-value you create a local copy of passed data. As a result changes done in the function will not affect the original one. 
// 1. Pass by Value
void swapByValue(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 2. Pass by Reference
//In this we create a reference. Changes done will be seen on the original also but the address is still kept secure. 
void swapByReference(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 3. Pass by Address / Pointer
//In this we pass an address from the main program. A pointer points to this address. Manipulation done on the address will also affect the original data. 
void swapByAddress(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "\nOriginal values:";
    cout << "\na = " << a << ", b = " << b << endl;

    // --------------------------------
    // PASS BY VALUE
    // --------------------------------
    int x = a;
    int y = b;

    swapByValue(x, y);

    cout << "\nAfter Pass by Value:";
    cout << "\nx = " << x << ", y = " << y << endl;


    // --------------------------------
    // PASS BY REFERENCE
    // --------------------------------
    int p = a;
    int q = b;

    swapByReference(p, q);

    cout << "\nAfter Pass by Reference:";
    cout << "\np = " << p << ", q = " << q << endl;


    // --------------------------------
    // PASS BY ADDRESS
    // --------------------------------
    int m = a;
    int n = b;

    swapByAddress(&m, &n);

    cout << "\nAfter Pass by Address:";
    cout << "\nm = " << m << ", n = " << n << endl;

    return 0;
}


