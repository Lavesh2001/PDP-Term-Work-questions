#include<iostream>
using namespace std;
int partition(int arr[],int l,int u)
{
    int pivot=arr[l],temp;
    int start=l,end=u;
    while(start<end)
    {
        while(arr[start]<=pivot)
        start++;
        while(arr[end]>pivot)
        end--;
        if(start<end)
        {
            temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
        }
    }
    temp=arr[l];
    arr[l]=arr[end];
    arr[end]=temp;
    return end;
}
void quicksort(int arr[],int l,int u)
{
    if(l<u)
    {
        int loc=partition(arr,l,u);
        quicksort(arr,l,loc-1);
        quicksort(arr,loc+1,u);
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
    quicksort(arr,0,n-1);
    cout<<"Array after sorting: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}