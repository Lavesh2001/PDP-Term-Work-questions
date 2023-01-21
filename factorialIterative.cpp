#include<iostream>
using namespace std;
int factorial(int n)
{
   int fact=1;
   for(int i=1;i<=n;i++)
   {
    fact*=i;
   }
   return fact;
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