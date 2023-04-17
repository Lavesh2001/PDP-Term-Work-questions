#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    Node *arr[26];
    int countwords;
    int  countprefix;
    Node()
    {
        for(int i=0;i<26;i++)
        arr[i]=NULL;
        countwords=0,countprefix=0;
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
    void increaseCountWord()
    {
        countwords++;
    }
    void increasePrefix()
    {
        countprefix++;
    }
    void decreaseCountWord()
    {
        countwords--;
    }
    void decreasePrefix()
    {
        countprefix--;
    }
    int getcountWords()
    {
        return countwords;
    }
    int getcountPrefix()
    {
        return countprefix;
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
        temp->increasePrefix();
        temp=temp->getNext(word[i]);
    }
    temp->increaseCountWord();
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
   return temp->countwords;
}
int countWordsEqualTo(string word)
{
    Node *temp=root;
    for(int i=0;i<word.length();i++)
    {
        if(!temp->contains(word[i]))
        return 0;
        temp=temp->getNext(word[i]);
    }
    return temp->getcountWords();
}
int countWordsStartWith(string prefix)
{
    Node *temp=root;
    for(int i=0;i<prefix.length();i++)
    {
        if(!temp->contains(prefix[i]))
        return 0;
        temp=temp->getNext(prefix[i]);
    }
    return temp->getcountPrefix();
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
void erase(string word)
{
    Node *temp=root;
    if(search(word)==false)
    return ;
    for(int i=0;i<word.size();i++)
    {
        temp->decreasePrefix();
        temp=temp->getNext(word[i]);
    }
    temp->decreaseCountWord();
}
int main()
{
    return 0;
}