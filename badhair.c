#include <stdio.h>
#define MAX_N   80000

int stack[MAX_N+1]={0,};
int h[MAX_N+1];

void get_height(FILE *fp,int n)
{
    int i;
    for(i=1;i<=n;i++)
        fscanf(fp,"%d",&h[i]);
}

void get_sum(FILE *fp,int n)
{
    int i;
    int c[n+1];
    int top=0;
    int sum=0;
    for(i=n;i>0;i--)
    {
        c[i]=0;
        while(top>0&&h[i]>h[stack[top]])
            c[i]+=c[stack[top--]]+1;

        sum+=c[i];
        stack[++top]=i;
    }

    fprintf(fp,"%d",sum);
}

int main()
{
    FILE *fp1;
    FILE *fp2;

    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");

    int n;
    fscanf(fp1,"%d",&n);

    get_height(fp1,n);
    get_sum(fp2,n);
}