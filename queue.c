#include <stdio.h>
#define MAX_N   1000

int main()
{
    FILE *fp1;
    FILE *fp2;

    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");

    int n;
    fscanf(fp1,"%d",&n);

    int i;
    int work;
    int rear=0;
    int front=1;
    int queue[MAX_N]={0,};
    for(i=0;i<n;i++)
    {
        fscanf(fp1,"%d",&work);

        if(work==1)
            fscanf(fp1,"%d",&queue[++rear]);

        else if(work==2)
        {
            if(front<=rear)
                front++;
        }
    }

    if(front==rear)
        fprintf(fp2,"-1");
    else
    {
        fprintf(fp2,"%d\n",rear-front+1);
        int i;
        for(i=front;i<=rear;i++)
            fprintf(fp2,"%d ",queue[i]);
    }
    
    
}