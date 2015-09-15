#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<sstream>
#include<cstring>
#include<string>
#include<cmath>
#include<graphics.h>
#define pi 2.0*acos(0.0)
#define M 2000000
#define pb push_back
using namespace std;

struct process{
    int priority,time;
    string arr;
}P;
bool com(process A, process B)
{
    if(A.priority!=B.priority)
    {
        return A.priority<B.priority;
    }
    else if(A.time==B.time)
    {
        return A.arr>B.arr;
    }
    return A.time<B.time;
}
//bool com1(process A, process B)
//{
//    return A.arr>B.arr;
//}
int main()
{
    int i,t,m,x,wait=0,turn=0,len;
    char str[22];
    vector<string>as;
    vector<string>ds;
    //stringstream ss;
    vector<process>V;
    //freopen("in.txt","r",stdin);
    scanf("%d\n",&t);
    for(x=1;x<=t;x++)
    {
        //gets(str);
        //ss<<"zxcxz 12 31";
        //ss>>str2>>m>>n;
        m=0;
        while(m<5)
        {
            scanf("%s%d%d\n",str,&P.time,&P.priority);
            //cin>>P.arr>>P.priority>>P.time;
            P.arr=str;
            V.pb(P);
            m++;
        }
        sort(V.begin(),V.end(),com);
        printf("\n|-----------------------------------------------------------------------------|\n");
        printf("| Process\t| Priority\t| Burst Time\t| Waiting Time  | Turnarround |");
        printf("\n|-----------------------------------------------------------------------------|\n");
        len=V.size();
        for(i=0;i<len;i++)
        {
            turn+=V[i].time;
            cout<<"| "<<V[i].arr<<"\t\t| "<<V[i].priority<<"\t\t| "<<V[i].time<<"\t\t| "<<wait<<"\t\t| "<<turn<<"\t\t|\n";
            wait+=V[i].time;
        }
        printf("|-----------------------------------------------------------------------------|\n");
        printf("\n\n\tTotal Waiting Time =\t%d",wait-V[len-1].time);
        printf("\n\n\tTurnaround Time =\t%d\n\n\n",turn);
    }
    return 0;
}
