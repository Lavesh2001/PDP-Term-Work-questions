#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int kmp(string text,string pattern)
{
    int n=text.length(),m=pattern.length(),prelps=0,i=1,j=0;
    vector<int>lps(m,0);
    for(i=1;i<m;)
    {
        if(pattern[i]==pattern[prelps])
        {
            lps[i]=prelps+1;
            prelps++;
            i++;
        }
        else
        {
            if(prelps==0)
            {
                lps[i]=0;
                prelps++;
                i++;
            }
            else
            {
                prelps=lps[prelps-1];
            }
        }
    }
    i=0;
    while(i<n)
    {
        if(text[i]==pattern[j])
        {
            i++;
            j++;
        }
        else{
            if(j==0)
            i++;
            else
            j=lps[j-1];
        }
        if(j==m)
        return i-m;
    }
    return -1;
}
int main()
{
    string text,pattern;
    cout<<"Enter the text string: ";
    cin>>text;
    cout<<"Enter the pattern string: ";
    cin>>pattern;
    int ind=kmp(text,pattern);
    if(ind==-1)
    cout<<"Pattern is not found"<<endl;
    else
    cout<<"Pattern is found at index: "<<ind<<endl;
    return 0;
}