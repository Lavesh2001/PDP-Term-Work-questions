#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int MCM(int arr[],int n)
{
    int dp[n][n];
    for(int i=1;i<n;i++)
    dp[i][i]=0;
    for(int i=n-1;i>=1;i--)
    {
        for(int j=i+1;j<n;j++)
        {
            int mn=INT_MAX;
            for(int k=i;k<j;k++)
            {
                int op=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                if(op<mn)
                mn=op;
            }
            dp[i][j]=mn;
        }
    }
    return dp[1][n-1]; 
}
int main()
{
    int n;
    cout<<"Enter the n: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int res=MCM(arr,n);
    cout<<"Minimum opeartion in matrix multiplication are: "<<res<<endl;
    return 0;
}