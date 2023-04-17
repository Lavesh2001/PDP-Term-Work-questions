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
        if(!temp->contains(word[i]))
        {
            temp->put(word[i],new Node()); 
        }
        temp->getNext(word[i]);
    }  
    temp->setFlag();
} 
bool checkPrefixExist(string word)
{
    Node* node = root;
		for(auto ch: word) {
			if(!node->contains(ch))
				return false;
			
			node = node->getNext(ch);
			if(!node->isflag())
				return false;
		}

		return true;
}
string longestWord(vector<string>&words)
{     
    for(int i=0;i<words.size();i++)
    {
        insert(words[i]);
    }
    string res="";
    for(int i=0;i<words.size();i++)
    { 
       if(checkPrefixExist(words[i]))
       {
            if(words[i].length()>res.length())
            {
                res=words[i];
            }
            else if(words[i].length()==res.length()&&words[i]<res)
            {
                res=words[i];
            }
       }
    }
    return res;
}
int main()
{    
    int n;
    cout<<"Enter the number of words: ";
    cin>>n;
    vector<string>words;
    cout<<"Enter the words:"<<endl;
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        words.push_back(str);
    }
    string res=longestWord(words);
    cout<<"Longest words having all its prefixes in the words: "<<res<<endl;
    return 0;
}