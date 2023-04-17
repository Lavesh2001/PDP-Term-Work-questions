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
Node * root=new Node();
int distinctSubstrings(string str)
{
    Node *temp=root;
    int n=str.length(),cnt=0;
    for(int i=0;i<n;i++)
    {
        temp=root;
        for(int j=i;j<n;j++)
        {
            if(!temp->contains(str[j]))
            {
                Node *newnode=new Node();
                temp->put(str[j],newnode);
                temp=temp->getNext(str[j]);
                temp->setFlag();
                cnt++;
            }
            else
            temp=temp->getNext(str[j]);
        }

    }
    return cnt;
}
int main()
{    
    string str;
    cout<<"Enter the string: ";
    cin>>str;
    int res=distinctSubstrings(str);
    cout<<"Number of distinst substrings: "<<res<<endl;
    return 0;
}