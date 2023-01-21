#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int coinchange(vector<int>coin,int n,int sum)
{
    vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
    for(int i=0;i<=n;i++)
    dp[i][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(coin[i-1]<=j)
            {
                dp[i][j]=dp[i][j-coin[i-1]]+dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}
int main()
{
    int n;
    cout<<"Enter the number of coins: ";
    cin>>n;
    vector<int>coin(n);
    cout<<"Enter the coin value for each coin: ";
    for(int i=0;i<n;i++)
    {
        cin>>coin[i];
    }
    int sum;
    cout<<"Enter the sum that you want to make from coins: ";
    cin>>sum;
    int res=coinchange(coin,n,sum);
    cout<<"Total number of ways to make sum from coins: "<<res<<endl;

    return 0;
}
