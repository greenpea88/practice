#include <stdio.h>
#define MAX_N   7

int check[MAX_N]={0,};
int l[MAX_N];
int cnt=0;

void  line(FILE *fp,int n,int m,int i)
{
    if(i>n)
    {
        int x;
        for(x=1;x<=n;x++)
            fprintf(fp,"%d ",l[x]);
        fprintf(fp,"\n");
        cnt++;
    }
    else
    {
        int x;
        for(x=1;x<=m;x++)
        {
            if(check[x]==0)
            {
                l[i]=x;
                check[x]=1;
                line(fp,n,m,i+1);
                check[x]=0;
            }
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

    line(fp2,n,m,1);
    fprintf(fp2,"%d",cnt);
}