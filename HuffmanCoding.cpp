#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct huffmanTreeNode
{
    char data;
    int freq;
    huffmanTreeNode *left,*right;
    huffmanTreeNode(char data,int freq)
    {
        left=right=NULL;
        this->data=data;
        this->freq=freq;
    }
};
struct compare
{
    bool operator()(huffmanTreeNode *l,huffmanTreeNode *r)
    {
        return (l->freq>r->freq);
    }
};
void printcodes(huffmanTreeNode *root,string str)
{
    if(root==NULL)
    return;
    if(root->data!='$')
    cout<<root->data<<": "<<str<<endl;
    printcodes(root->left,str+"0");
    printcodes(root->right,str+"1");
}
void huffmancodes(char ch[],int freq[],int n)
{
    huffmanTreeNode *left,*right,*top;
    priority_queue<huffmanTreeNode*,vector<huffmanTreeNode*>,compare>pq;
    for(int i=0;i<n;i++)
    pq.push(new huffmanTreeNode(ch[i],freq[i]));
    while(pq.size()>1)
    {
        left=pq.top();
        pq.pop();
        right=pq.top();
        pq.pop();
        top=new huffmanTreeNode('$',left->freq+right->freq);
        top->left=left;
        top->right=right;
        pq.push(top);
    }
    printcodes(pq.top(),"");
}
int main()
{   
    int n;
    cout<<"Enter the number of characters: ";
    cin>>n;
    char ch[n];
    int freq[n];
    cout<<"Enter the each character and its frequency: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>ch[i];
        cin>>freq[i];
    }
    huffmancodes(ch,freq,n);
    return 0;
}