#include<iostream>
using namespace std;
int fibo(int n)
{
    if(n==1)
    return 0;
    if(n==2)
    return 1;
    else 
    return fibo(n-1)+fibo(n-2); 
}
int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"Fibonacci Series: ";
    for(int i=1;i<=n;i++)
    {
         cout<<fibo(i)<<" ";
    }
    return 0;
}