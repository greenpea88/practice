#include <stdio.h>
#define MAX_SIZE    10

int main()
{
    FILE *fp1;
    FILE *fp2;

    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");

    int n;
    fscanf(fp1,"%d",&n);

    int stack[n+1];

    int work;
    int top=0;
    while(1)
    {
        fscanf(fp1,"%d",&work);
        
        if(work==0) 
            break;
        else if(work==1)
        {
            if(top<n)
                fscanf(fp1,"%d",&stack[++top]);
        }
        else if(work==2)
        {
            if(top!=0)
                top--;
        }
        printf("%d\n",top);
    }

    int i;
    fprintf(fp2,"%d\n",top);
    for(i=top;i>0;i--)
        fprintf(fp2,"%d ",stack[i]);
}