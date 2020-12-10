#include <stdio.h>
#define MAX_N   7

int s[MAX_N+1]={0,};
int cnt=0;

void select(FILE *fp,int n,int m,int i)
{
    if(i>m)
    {
        int x;
        for(x=1;x<=m;x++)
            fprintf(fp,"%d ",s[x]);
        fprintf(fp,"\n");
        cnt++;
    }
    else
    {
        int x;
        for(x=s[i-1];x<=n;x++)
        {
            s[i]=x;
            select(fp,n,m,i+1);
        }
    }
    
}

int  main()
{
    FILE *fp1;
    FILE *fp2;

    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");

    int n,m;
    fscanf(fp1,"%d %d",&n,&m);

    s[0]=1;
    select(fp2,n,m,1);
    fprintf(fp2,"%d",cnt);
}