#include <stdio.h>
#define MAX_N   7

int c[MAX_N+1];
int check[MAX_N+1]={0,};

void choose(FILE *fp,int n,int m,int i)
{
    if(i>m)
    {
        int x;
        for(x=1;x<=m;x++)
            fprintf(fp,"%d ",c[x]);
        fprintf(fp,"\n");
    }
    else
    {
        int x;
        for(x=1;x<=n;x++)
        {
            if(check[x]==0)
            {
                c[i]=x;
                check[x]=1;
                choose(fp,n,m,i);
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

}