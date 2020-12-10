#include <stdio.h>
#define MAX_N   100

int graph[MAX_N+1][MAX_N+1];
int queue[MAX_N+1];
int visit[MAX_N+1]={0,};

void get_graph(FILE *fp,int e)
{
    int i;
    int x,y;
    for(i=1;i<=e;i++)
    {
        fscanf(fp,"%d %d",&x,&y);
        graph[x][y]=graph[y][x]=1;
    }
}

void infected(FILE *fp,int n)
{
    int front=1;
    int rear=0;

    queue[++rear]=1;
    visit[1]=1;

    int v,i;
    int cnt=0;
    while(front<=rear)
    {
        v=queue[front++];
        for(i=1;i<=n;i++)
        {
            if(visit[i]==0&&graph[v][i]==1)
            {
                queue[++rear]=i;
                visit[i]=1;
                cnt++;
            }
        }
    }
    fprintf(fp,"%d",cnt);
}

int main()
{
    FILE *fp1;
    FILE *fp2;

    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");

    int n,e;
    fscanf(fp1,"%d",&n);
    fscanf(fp1,"%d",&e);

    get_graph(fp1,e);
    infected(fp2,n);
}