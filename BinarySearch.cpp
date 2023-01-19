#include<iostream>
using namespace std;
int main()
{
    int n,num,l,u,mid;
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
    l=0,u=n-1;
    while(l<=u)
    {
        mid=(l+u)/2;
        if(arr[mid]==num)
        {
            cout<<num<<" is present in array at index "<<mid<<endl;
            break;
        }
        else if(arr[mid]<num)
        l=mid+1;
        else 
        u=mid-1;
    }
    if(l>u)
    {
        cout<<num<<" is not present in array"<<endl;
    }
    return 0;
}