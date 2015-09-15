#include<iostream>
#include<cstdio>
#include<ctime>
#define SIZE 10000
using namespace std;
unsigned long long drawTable[SIZE][SIZE];//Some time we need global declear
void nCr()
{
    //when we use this algoritham function should not use.
    int i,j;
    for(i=0;i<SIZE;i++)
    {
        drawTable[0][i]=1;//rwo 0 asign 1 1 1 1 1 ........
        drawTable[1][i]=i;//row one create 1 2 3 4 5 6...
    }
    for(i=2;i<SIZE;i++)//Here row is value of r
    {
        for(j=i;j<SIZE;j++)//Here coloum is n
        {
            drawTable[i][j]=drawTable[i-1][j-1]+drawTable[i][j-1];
        }
    }


    /**For output Test not necessary***/
   /* for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
            cout<<drawTable[i][j]<<"\t";

        printf("\n\n");
    }*/

}
int main()
{
    int o,p;
    nCr();

    while(scanf("%d %d",&o,&p)==2)
    {
        cout<<drawTable[p][o]<<endl;
    }
}
