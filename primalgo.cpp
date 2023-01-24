#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void miniSpanningTree(vector<pair<int,int>>adj[],int n,int e)
{
    vector<pair<int,int>>mst;
    vector<int>vis(n,0);
    int mst_sum=0;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    pq.push({0,{0,-1}});
    while(pq.size()>0)
    {
        auto it=pq.top();
        pq.pop();
        int ver=it.second.first;
        int parent=it.second.second;
        int wt=it.first;
        if(vis[ver]==1)
        continue;
        if(parent!=-1)
        mst.push_back({ver,parent});
        mst_sum+=wt;
        vis[ver]=1;
        for(auto it:adj[ver])
        {   
            if(!vis[it.first])
            pq.push({it.second,{it.first,ver}});
        }
    }
    cout<<"Minimum Spanning Tree: "<<endl;
    for(auto it:mst)
    {
        cout<<it.first<<" "<<it.second<<endl;
    } 
    cout<<"Total sum of MST: "<<mst_sum<<endl;

}
int main()
{
    int n,e;
    cout<<"Enter the number of vertices and edges: ";
    cin>>n>>e;
    cout<<"Enter the edges: "<<endl;
    vector<pair<int,int>>adj[n];
    for(int i=0;i<e;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    miniSpanningTree(adj,n,e);
    return 0;
}