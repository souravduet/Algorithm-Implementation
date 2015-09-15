#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define SIZE 50

using namespace std;

int arr[SIZE]={0},mod=3;

bool gen_Bitwise_prime()
{
    int dx,bit,j,i,sq=sqrt(SIZE);
    printf("arr[10]= %d\n",arr[0]);
    for(i=2;i<=sq;i++)
    {
        dx=i/mod;
        bit=i%mod;
        if(!(arr[dx]&1<<bit))
        {
            //printf("i= %d, dx= %d, bit= %d,\n",i,dx,bit);
            for(j=i+i;j<SIZE;j+=i)
            {
                dx=j/mod;
                bit=j%mod;
                arr[dx]=arr[dx]|1<<bit;
                printf("j= %d, dx= %d, bit= %d,\n",j,dx,bit);
                printf("arr[dx]= %d\n\n",arr[dx]);
            }
        }
    }
    return 1;
}
bool chack_prime(int n)
{
    if((arr[n/mod]&1<<arr[n%mod])==0)
        return 1;
    return 0;
}
int main()
{
    gen_Bitwise_prime();
    if(chack_prime(6))
        printf("Prime\n");
    else
        printf("Not prime\n");
    for(int t=0;t<20;t++)
    {
        printf("%d ",arr[t]);
    }
}
