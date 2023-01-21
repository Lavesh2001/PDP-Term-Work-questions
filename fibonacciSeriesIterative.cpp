#include<iostream>
using namespace std;
void fibonacciSeries(int n)
{
    int a=0,b=1,c;
    cout<<"Fibonacci Series: ";
    cout<<a<<" "<<b<<" ";
    for(int i=3;i<=n;i++)
    {
        c=a+b;
        cout<<c<<" ";
        a=b;
        b=c;
    }
}
int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;
    fibonacciSeries(n);
    return 0;
}