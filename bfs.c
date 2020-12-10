#include <stdio.h>
#define MAX_N   20

int graph[MAX_N+1][MAX_N+1];
int queue[MAX_N+1];
int visit[MAX_N+1]={0,};

void get_graph(FILE *fp,int n)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            fscanf(fp,"%d",&graph[i][j]);
    }
}

void bfs(FILE *fp,int start,int n)
{
    int front=1;
    int rear=0;

    queue[++rear]=start;
    visit[start]=1;

    int v,i;
    while(front<=rear)
    {
        fprintf(fp,"%d ",queue[front]);
        v=queue[front++];
        for(i=1;i<=n;i++)
        {
            if(visit[i]==0&&graph[v][i]==1)
            {
                queue[++rear]=i;
                visit[i]=1;
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

    int n,start;
    fscanf(fp1,"%d %d",&n,&start);

    get_graph(fp1,n);
    bfs(fp2,start,n);

}