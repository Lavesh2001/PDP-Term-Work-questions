#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class DisjointSet
{
    vector<int>rank,parent,size;
    public:
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }
    int findParent(int node)
    {
        if(node==parent[node])
        return node;
        
        return parent[node]=findParent(parent[node]);
    }
    void unionByRank(int u,int v)
    {
        int pu=findParent(u);
        int pv=findParent(v); 
        if(pu==pv)
        return;
        if(rank[pu]<rank[pv])
        {
            parent[pu]=pv;
        }
        else if(rank[pv]<rank[pu])
        {
            parent[pv]=pu;
        }
        else
        {
            parent[pv]=pu;
            rank[pu]++;
        }
    }
};
void MinimumSpanningTree(vector<pair<int,int>>adj[],int n,int e)
{
    vector<pair<int,pair<int,int>>>edges;
    for(int i=0;i<n;i++)
    {
        for(auto it:adj[i])
        {
            edges.push_back({it.second,{i,it.first}});
        }
    }
    sort(edges.begin(),edges.end());
    int mst_sum=0;
    vector<pair<int,int>>mst;
    DisjointSet ds(n);
    for(auto it:edges)
    {
        int wt=it.first;
        int u=it.second.first;
        int v=it.second.second;
        if(ds.findParent(u)!=ds.findParent(v))
        {
            mst_sum+=wt;
            mst.push_back({u,v});
            ds.unionByRank(u,v);
        }
    }
    cout<<"Minimum Spanning Tree:"<<endl;
    for(auto it:mst)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<"Sum of MST: "<<mst_sum<<endl;
}
int main()
{   
    int n,e;
    cout<<"Enter the number of vertices and edges: ";
    cin>>n>>e;
    vector<pair<int,int>>adj[n];
    cout<<"Enter the edges: "<<endl;
    for(int i=0;i<e;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    MinimumSpanningTree(adj,n,e);
    return 0;
}