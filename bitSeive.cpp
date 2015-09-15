//#include<bits/stdc++.h>
    #include<iostream>
    #include<cstdio>
    #include<cmath>
    using namespace std;
    int ary[3226009];
    int BitwiseSeive()
    {
        int m,n=100000001,i,loop,idx,bit,indix,location,j,p;
        m=sqrt(n);
        for(loop=3;loop<=m;loop+=2)
        {
            indix=loop/31;
            location=loop%31;
            location--;
            //printf(" \n%d %d\n",indix,location);
           if(!(ary[indix] &  (1<<location)))
           {
               //printf("%d ",loop);
               for(i=loop*loop;i<=n;i+=loop)
               {
                   idx=i/31;
                   bit=i%31;
                   bit--;
                   ary[idx]=ary[idx] | (1<<bit);
               }
           }
        }
        printf("%d\n",2);
        j=1;
        p=101;
        for(i=3;i<1000;i+=2)
        {
            idx=i/31;
            bit=i%31;
            bit--;
            if(!(ary[idx] & (1<<bit)))
            {
                j++;
                if(j==p)
                {
                    printf("%d\n",i);
                    p+=100;
                }
            }
        }
    }
    int main()
    {
        //printf("fd %d\n",1<<0);
        BitwiseSeive();
    }

