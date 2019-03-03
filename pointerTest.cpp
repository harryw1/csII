#include <iostream>
using namespace std;

int main()
{
    int x;
    int* y = &x;

    cout << x << endl;
    cout << &x << endl;
    cout << y << endl;
    cout << &y << endl;

    delete y;

    cout << x << endl;
    cout << &x << endl;
    cout << y << endl;
    cout << &y << endl;
}