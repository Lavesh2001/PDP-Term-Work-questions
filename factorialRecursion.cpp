#include<iostream>
using namespace std;
int factorial(int n)
{
    if(n==1)
    return n;
    return n*factorial(n-1);
}
int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int fact=factorial(n);
    cout<<"factorial of "<<n<<": "<<fact;
    return 0;
}