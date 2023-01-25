#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> BellamanFord(vector<vector<int>>edges,int n,int src)
{
    vector<int>dist(n,INT_MAX);
    dist[src]=0;
    for(int i=0;i<n-1;i++)
    {
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(dist[u]!=INT_MAX&&dist[u]+wt<dist[v])
            {
                dist[v]=dist[u]+wt;
            } 
        }    
    }
    return dist;
}
int main()
{   
    //Graph Must be directed and there is no negative cycle in the graph
    int n,e;
    cout<<"Enter the number of vertices and edges: ";
    cin>>n>>e;
    vector<vector<int>>edges;
    cout<<"Enter the edges: "<<endl;
    for(int i=0;i<e;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        vector<int>temp;
        temp.push_back(u);
        temp.push_back(v);
        temp.push_back(wt);
        edges.push_back(temp);
    }
    int src;
    cout<<"Enter the source: ";
    cin>>src;
    vector<int>dist=BellamanFord(edges,n,src);
    cout<<"Distance of each node from source are: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i<<" "<<dist[i]<<endl;
    }
    return 0;
}