#include <stdio.h>
#define MAX_SIZE    15

int  table[MAX_SIZE+2][MAX_SIZE+2];

int di[4]={0,1,0,-1};
int dj[4]={1,0,-1,0};

void init_table(int n)
{
    int i,j;

    for(i=0;i<n+2;i++)
    {
        for(j=0;j<n+2;j++)
        {
            if(i==0||i==n+1||j==0||j==n+1)
            {
                table[i][j]=-1;
            }
        }
    }
}

void fill_table(int  n,int start)
{
    int i=1;
    int j=1;
    int x=0;

    while(1)
    {
        if(table[i][j]!=0) break;
        table[i][j]=start;
        start++;

        if(table[i+di[x]][j+dj[x]]!=0)
        {
            x++;
            x=x%4;
        }
        i=i+di[x];
        j=j+dj[x];
    }
}

int main()
{
    FILE *fp1;
    FILE *fp2;

    fp1=fopen("input.txt","r");
    fp2=fopen("ouput.txt","w");


    int n,start;
    fscanf(fp1,"%d",&n);
    fscanf(fp1,"%d",&start);

    init_table(n);
    fill_table(n,start);
    int i,j;
    for(i=1;i<n+1;i++)
    {
        for(j=1;j<n+1;j++)
        {
            fprintf(fp2,"%d ",table[i][j]);
        }
        fprintf(fp2,"\n");
    }
}