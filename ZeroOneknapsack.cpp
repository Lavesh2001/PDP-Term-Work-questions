#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int zeroOneKnapsack(vector<int>weight,vector<int>value,int n,int w)
{
    vector<vector<int>>dp(n+1,vector<int>(w+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(weight[i-1]<=j)
            {
                dp[i][j]=max(value[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}
int main()
{
    int n,capacity;
    cout<<"Enter the number of items: ";
    cin>>n;
    vector<int>weight(n),value(n);
    cout<<"Enter the weight and value of each item: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>weight[i];
        cin>>value[i];
    }
    cout<<"Enter the capcity of knapsack: ";
    cin>>capacity;
    int res;
    res=zeroOneKnapsack(weight,value,n,capacity);
    cout<<"Maximum Value earned: "<<res<<endl;
    return 0;
}