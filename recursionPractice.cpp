#include <iostream>
using namespace std;

int factorial(int n);
int print_fib(int n);
int sum_fib(int n);

int main()
{
  int user_int;
  cout << "Enter an integer: ";
  cin >> user_int;

  cout << factorial(user_int);

  cout << endl;

  cout << sum_fib(user_int);

  cout << endl;

  //cout << print_fib(user_int);

}

int factorial(int n)
{

    if(n==1)
    {
        return 1;
    }
    return (n*factorial(n-1));

}

int sum_fib(int n)
{
    if(n==1)
    {
      return 1;
    }
    return (n+sum_fib(n-1));
}

int print_fib(int n)
{
  return 0;
}
