#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> activityselection(vector<int>start,vector<int>finish,int n)
{
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++)
    {
        v[i]=make_pair(finish[i],i);
    }
    sort(v.begin(),v.end());
    vector<int>res;
    res.push_back(v[0].second);
    int j=0;
    for(int i=1;i<n;i++)
    {
        if(start[v[i].second]>=finish[v[j].second])
        {
            res.push_back(v[i].second);
            j=i;
        }
    }
    return res;
}
int main()
{
    int n;
    cout<<"Enter the number of activities: ";
    cin>>n;
    vector<int>start(n),finish(n);
    cout<<"Enter the start en finish time of each activity: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>start[i];
        cin>>finish[i];
    }
    vector<int>res=activityselection(start,finish,n);
    sort(res.begin(),res.end());
    cout<<"Activities that can be completed: "<<endl;
    cout<<"Activity\tstart time\tfinish time"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<res[i]<<"\t\t"<<start[res[i]]<<"\t\t"<<finish[res[i]]<<endl;
    }
    return 0;
}