#include <stdio.h>
#define MAX_N   100

int spiral_maze[MAX_N+3][MAX_N+3];

int di[4]={0,1,0,-1};
int dj[4]={1,0,-1,0};

void init_maze(int n)
{
    int i,j;
    for(i=0;i<n+3;i++)
    {
        for(j=0;j<n+3;j++)
        {
            if(i==0||i==n+2||j==0||j==n+2) 
                spiral_maze[i][j]=-1;
        }
    }
}

void make_maze(int n)
{
    int i=1;
    int j=1;
    int x=0;
    int num=1;

    while(1)
    {
        if(spiral_maze[i+di[x]][j+dj[x]]!=0)
            break;
        spiral_maze[i][j]=num;
        num++;
        if(num==10) 
            num=1;

        if(spiral_maze[i+di[x]*2][j+dj[x]*2]!=0)
            x=(x+1)%4;
        
        i=i+di[x];
        j=j+dj[x];
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

    init_maze(n);
    make_maze(n);

    int i,j;
    for(i=1;i<n+1;i++)
    {
        for(j=1;j<n+1;j++)
        {
            if(spiral_maze[i][j]==0) 
                fprintf(fp2," ");
            else 
                fprintf(fp2,"%d",spiral_maze[i][j]);
        }
        fprintf(fp2,"\n");
    }
}