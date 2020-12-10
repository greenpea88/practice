#include <stdio.h>
#define MAX_N   50000

struct cow
{
    int h;
    int v;
};

struct cow cows[MAX_N];
int stack[MAX_N]={0,};

void init(FILE *fp,int n)
{
    int i;
    for(i=1;i<=n;i++)
        fscanf(fp,"%d %d",&cows[i].h,&cows[i].v);
}

void get_max(FILE *fp,int n)
{
    int i;
    int hear[n+1];
    int top=0;
    int max=0;

    for(i=1;i<=n;i++)
    {
        hear[i]=0;

        while(top>0&&cows[i].h>cows[stack[top]].h)
            hear[i]+=cows[stack[top--]].v;
            
        stack[++top]=i;
    }

    for(i=n;i>n;i--)
    {
        while(top>0&&cows[i].h>cows[stack[top]].h)
            hear[i]+=cows[stack[top--]].v;

        stack[++top]=i;
    }

    for(i=1;i<=n;i++)
    {
        printf("%d %d\n",i,hear[i]);
        if(max<hear[i])
            max=hear[i];
    }

    fprintf(fp,"%d",max);
}

int main()
{
    FILE *fp1;
    FILE *fp2;

    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");

    int n;
    fscanf(fp1,"%d",&n);

    init(fp1,n);
    get_max(fp2,n);
}