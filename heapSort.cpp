#include<iostream>
using namespace std;
void maxheapify(int arr[],int n,int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n&&arr[left]>arr[largest])
    largest=left;
    if(right<n&&arr[right]>arr[largest])
    largest=right;
    if(largest!=i)
    {
        int temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        maxheapify(arr,n,largest);
    }
}
void heapsort(int arr[],int n)
{
    for(int i=n/2;i>=0;i--)
    {
        maxheapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--)
    {
        int temp=arr[i];
        arr[i]=arr[0];
        arr[0]=temp;
        maxheapify(arr,i,0);
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
    heapsort(arr,n);
    cout<<"Array after sorting: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}