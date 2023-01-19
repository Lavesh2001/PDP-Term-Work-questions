#include<iostream>
using namespace std;
void merge(int *arr,int l,int mid,int u)
{
    int  i=l,j=mid+1,brr[u+1],k=l;
    while(i<=mid&&j<=u)
    {
        if(arr[i]<=arr[j])
        {
           brr[k]=arr[i];
           i++; 
        }
        else
        {
            brr[k]=arr[j];
            j++;
        }
        k++;
    }
    while(i<=mid)
    {
        brr[k]=arr[i];
        i++; 
        k++;
    }
    while(j<=u)
    {
        brr[k]=arr[j];
        j++; 
        k++;
    }
    for(int i=l;i<=u;i++)
    {
        arr[i]=brr[i];
    }
}
void mergesort(int *arr,int l,int u)
{
    if(l<u)
    {
        int mid=(l+u)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,u);
        merge(arr,l,mid,u);
    }
}
int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);
    cout<<"Array after sorting :";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}