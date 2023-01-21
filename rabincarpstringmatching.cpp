#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int RabinCarp(string text,string pattern)
{
    int n=text.length(),m=pattern.length();
    int d=256,q=INT_MAX,p=0,t=0,h=1,i,j;
    for(i=0;i<m-1;i++)
    {
        h=(h*d)%q;
    }
    for(i=0;i<m;i++)
    {
        p=(p*d+pattern[i])%q;
        t=(t*d+text[i]);
    }
    for(i=0;i<=n-m;i++)
    {
        if(p==t)
        {
            for(j=0;j<m;j++)
            {
                if(text[i+j]!=pattern[j])
                break;
            }
            if(j==m)
            return i;
        }
        if(i<n-m)
        {
            t=((t-text[i]*h)*d+text[i+m])%q;
            if(t<0)
            t=t+q;
        }   
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
    int ind=RabinCarp(text,pattern);
    if(ind==-1)
    cout<<"Pattern is not found"<<endl;
    else
    cout<<"Pattern is found at index: "<<ind<<endl;
    return 0;
}