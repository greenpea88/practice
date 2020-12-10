#include <stdio.h>
#define MAX_N   100

int main()
{
    FILE *fp1;
    FILE *fp2;

    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");

    int n,m,k;
    fscanf(fp1,"%d %d %d",&n,&m,&k);

    int rear=0;
    int front=1;
    int queue[MAX_N]={0,};
    int i;
    for(i=m;i<=n;i++)
        queue[++rear]=i;
    
    for(i=1;i<=m-1;i++)
        queue[++rear]=i;

    while(rear!=front)
    {
        fprintf(fp2,"%d ",queue[front]);
        front++;
        for(i=1;i<k;i++)
            queue[++rear]=queue[front++];
    }
    fprintf(fp2,"\n%d",queue[front]);
    
}