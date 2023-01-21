#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct taskinfo
{
    int id;
    int dead;
    int profit;
};
bool comp(taskinfo a, taskinfo b)
{
    return (a.profit > b.profit);
}
void taskschedule(taskinfo task[],int n)
{
    sort(task+0,task+n,comp);
    int mx=task[0].dead;
    for(int i=1;i<n;i++)
    {
        if(task[i].dead>mx)
        mx=task[i].dead;
    }
    int slot[mx+1],total_profit=0;
    for(int i=0;i<=mx;i++)
    slot[i]=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=task[i].dead;j>0;j--)
        {
            if(slot[j]==-1)
            {
                slot[j]=task[i].id;
                total_profit+=task[i].profit;
                break;
            }
        }
    }
    cout<<"Tasks that can be completed in their deadline are: ";
    for(int i=1;i<=mx;i++)
    {
        if(slot[i]!=-1)
        cout<<slot[i]<<" ";
    }
    cout<<endl<<"Total Profit earned: "<<total_profit;
}
int main()
{
    int n;
    cout<<"Enter the number of tasks: ";
    cin>>n;
    taskinfo task[n];
    cout<<"Enter the task id ,task deadline and task profit for each task: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>task[i].id;
        cin>>task[i].dead;
        cin>>task[i].profit;
    }
    taskschedule(task,n);
    return 0;
}