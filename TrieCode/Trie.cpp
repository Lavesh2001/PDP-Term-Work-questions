#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    Node *arr[26];
    int flag;
    Node()
    {
        for(int i=0;i<26;i++)
        arr[i]=NULL;
        flag=false;
    }
    bool contains(char c)
    {
        return (arr[c-'a']!=NULL);
    }
    void put(char ch,Node *newnode)
    {
        arr[ch-'a']=newnode;
    }
    Node * getNext(char ch)
    {
        return arr[ch-'a'];
    }
    void setFlag()
    {
        flag=true;
    }
    bool isflag()
    {
        return flag;
    }
};

Node *root=new Node();
void insert(string word)
{
    Node *temp=root;
    for(int i=0;i<word.length();i++)
    {
        //previous instance of word[i]
        if(!temp->contains(word[i]))
        {
            Node *newnode=new Node();
            temp->put(word[i],newnode);
        }
        temp=temp->getNext(word[i]);
    }
    temp->setFlag();
}
bool search(string word)
{
    Node * temp=root;
    for(int i=0;i<word.length();i++)
    {
        if(!temp->contains(word[i]))
        {
            return false;
        }
        temp=temp->getNext(word[i]);
    }
   return temp->isflag();
}
bool startWith(string prefix)
{
    Node * temp=root;
    for(int i=0;i<prefix.length();i++)
    {
        if(!temp->contains(prefix[i]))
        return false;
        temp=temp->getNext(prefix[i]);
    }
    return true;
}
int main()
{
    return 0;
}