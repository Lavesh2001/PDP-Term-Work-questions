#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    Node* arr[2];
    Node()
    {
        arr[0]=NULL;
        arr[1]=NULL;
    }
    bool contains(int bitno)
    {
        return arr[bitno]!=NULL;
    }
    void put(int bitno,Node *node)
    {
        arr[bitno]=node;
    }
    Node *getNext(int bitno)
    {
        return arr[bitno];
    }

};
Node *root=new Node();
void insert(int n)
{

}
int findMinXor(int arr[],int n)
{   
    int mnxor=arr[0]^arr[1];
    insert(arr[0]);
    for(int i=0;i<n;i++)
    {         
    }
}
int main()
{
    return 0;
}