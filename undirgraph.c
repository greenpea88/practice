#include <stdio.h>
#define MAX_N   100

int graph[MAX_N+1][MAX_N+1];

void get_graph(FILE *fp,int e)
{
    int i;
    for(i=0;i<e;i++)
    {
        int x,y;
        fscanf(fp,"%d %d",&x,&y);
        graph[x][y]=1;
        graph[y][x]=1;
    }
}

void print_graph(FILE *fp,int n)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(graph[i][j]==1)
                fprintf(fp,"%d ",graph[i][j]);
            else
                fprintf(fp,"0 ");
            
        }

        fprintf(fp,"\n");
    }
}

int main()
{
    FILE *fp1;
    FILE *fp2;

    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");

    int n;
    fscanf(fp1,"%d",&n);
    int e;
    fscanf(fp1,"%d",&e);

    get_graph(fp1,e);
    print_graph(fp2,n);
}