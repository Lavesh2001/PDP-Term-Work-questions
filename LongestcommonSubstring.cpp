#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int lcsubstring(string str1,string str2)
{
    int n=str1.length(),m=str2.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    int res=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(str1[i-1]==str2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
                res=max(res,dp[i][j]);
            }
            else
            {
                dp[i][j]=0;
            }
        }
    }
    return res;
}
int main()
{
    string str1,str2;
    cout<<"Enter the string 1: ";
    cin>>str1;
    cout<<"Enter the string 2: ";
    cin>>str2;
    int res=lcsubstring(str1,str2);
    cout<<"Length of longest commom substring: "<<res<<endl;
    return 0;
}