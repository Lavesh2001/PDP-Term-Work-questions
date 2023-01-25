#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> floydWarshall(vector<vector<int>>graph,int n)
{  
    vector<vector<int>>dist(n,vector<int>(n));
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {  
            if(graph[i][j]==-1)
            dist[i][j]=INT_MAX;
            else
            dist[i][j]=graph[i][j];
        }
    }
    for (k=0;k<n;k++) 
    {
        for (i=0;i<n;i++) 
        {
            for (j=0;j<n;j++) 
            {
                if ((dist[k][j]!=INT_MAX && dist[i][k]!=INT_MAX) && dist[i][j] > (dist[i][k] + dist[k][j]))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    return  dist;
}
int main()
{
    int n;
    cout<<"Enter the number:";
    cin>>n;
    vector<vector<int>>graph(n,vector<int>(n));
    cout<<"Enter the graph in the matrix form: "<<endl;
    cout<<"Enter edge weight if they are connected else enter -1:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int wt;
            cin>>wt;
            graph[i][j]=wt;
        }
    }
    vector<vector<int>>dist=floydWarshall(graph,n);
    cout<<"Distance matrix is:" <<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {   
            if(dist[i][j]==INT_MAX)
            cout<<"-1"<<" ";
            else
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
