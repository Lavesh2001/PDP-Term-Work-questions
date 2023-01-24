#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> DijkstraAlgo(vector<pair<int,int>>adj[],int n,int src)
{
    vector<int>d(n);
    for(int i=0;i<n;i++)
    {
        d[i]=INT_MAX;
    }
    d[src]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src});
    while(pq.size()>0)
    {
        int dist=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto it:adj[node])
        {
            int edgewt=it.second;
            int adjnode=it.first;
            if(dist+edgewt<d[adjnode])
            {
                d[adjnode]=dist+edgewt;
                pq.push({d[adjnode],adjnode});
            }
        }
    }
    return d;
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
    int src;
    cout<<"enter the source Node: ";
    cin>>src;
    vector<int>dist=DijkstraAlgo(adj,n,src);
    cout<<"Distance of each node from source node :"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i<<" "<<dist[i]<<endl;
    }
    return 0;
}