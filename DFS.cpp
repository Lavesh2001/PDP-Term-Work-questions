#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> DFS(vector<vector<int>>adj,int n,int start)
{
    vector<int>vis(n,0);
    vector<int>res;
    stack<int>st;
    st.push(start);
    while(st.size()>0)
    {
        int node=st.top();
        st.pop();
        if(!vis[node])
        {
            res.push_back(node);
            vis[node]=1;
        }
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                st.push(it);
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
    cout<<"Enter the starting node for DFS: ";
    cin>>start;
    vector<int>res=DFS(adj,n,start);
    cout<<"DFS of the graph: ";
    for(int i=0;i<n;i++)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}