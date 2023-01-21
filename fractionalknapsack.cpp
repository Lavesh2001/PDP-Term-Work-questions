#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool compare(pair <float, int> p1, pair <float, int> p2)
{
	return p1.first > p2.first;
}
float fractionalknapsack(vector<int>weight,vector<int>profit,int n,int capacity)
{
    vector<pair<float,int>>pw(n);
    for(int i=0;i<n;i++)
    {
        pw[i]=make_pair((float)profit[i]/weight[i],i);
    }
    sort(pw.begin(),pw.end(),compare);
    float res=0;
    for(int i=0;i<n;i++)
    {
        if(weight[pw[i].second]<=capacity)
        {
            res+=profit[pw[i].second];
            capacity-=weight[pw[i].second];
        }
        else{
            res+=pw[i].first*capacity;
            break;
        }
    }
    return res;
}
int main()
{   
    int n;
    cout<<"Enter the number of items: ";
    cin>>n;
    vector<int>weight(n),profit(n);
    cout<<"Enter the weight and profit of each item: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>weight[i];
        cin>>profit[i];
    }
    float capacity;
    cout<<"Enter the capcity of knapsack: ";
    cin>>capacity;
    float p;
    p=fractionalknapsack(weight,profit,n,capacity);
    cout<<"Total profit earned: "<<p<<endl;
    return 0;
}