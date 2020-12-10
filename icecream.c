#include <stdio.h>
#define MAX_N   7

int c[MAX_N+1]={0,};
int cnt=0;

void choose(FILE *fp,int n,int m,int i)
{
    if(i>n)
    {
        int x;
        for(x=1;x<=n;x++)
            fprintf(fp,"%d ",c[x]);
        fprintf(fp,"\n");
        cnt++;
    }

    else
    {
        int x;
        for(x=1;x<=m;x++)
        {
            c[i]=x;
            choose(fp,n,m,i+1);
        }
    }
    
}

int main()
{
    FILE *fp1;
    FILE *fp2;

    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");

    int n,m;
    fscanf(fp1,"%d %d",&n,&m);
    
    choose(fp2,n,m,1);
    fprintf(fp2,"%d",cnt);
}