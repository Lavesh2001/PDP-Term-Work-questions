#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> BFS(vector<vector<int>>adj,int n,int start)
{
    vector<int>vis(n,0);
    vector<int>res;
    queue<int>q;
    q.push(start);
    vis[start]=1;
    while(q.size()>0)
    {
        int node=q.front();
        q.pop();
        res.push_back(node);
        for(auto it:adj[node])
        {
            if(!vis[it])
            {   
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return res;
}
int main()
{
    int n,e;
    cout<<"Enter the number of vertices and edges: ";
    cin>>n>>e;
    vector<vector<int>>adj(n);
    cout<<"Enter the edges: "<<endl;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    int start;
    cout<<"Enter the starting node for BFS: ";
    cin>>start;
    vector<int>res=BFS(adj,n,start);
    cout<<"BFS of the graph: ";
    for(int i=0;i<n;i++)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}