#include<iostream>
#include<math.h>
using namespace std;
int JumpSearch(int arr[],int n,int num)
{
    int m=sqrt(n);
    int l=0,u=m;
    while(arr[min(u,n)-1]<num)
    {
        l=u;
        u+=m;
        if(l>=n)
        return -1;
    }
    while(l<u)
    {
        if(arr[l]==num)
        return l;
        l++;
    }
    return -1;
}
int main()
{
    int n,num;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array in sorted order: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the number that you want to search: ";
    cin>>num;
    int ind=JumpSearch(arr,n,num);
    if(ind==-1)
    cout<<num<<" is not present in array"<<endl;
    else
    cout<<num<<" is prsent in array at index "<<ind<<endl;
    return 0;
}