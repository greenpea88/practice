#include <stdio.h>

void get_max(int n,int *num,FILE *fp)
{
    int i,l,r;
    int start=0;
    int max=0;
    int sum=0;

    for(i=0;i<n;i++)
    {
        sum+=num[i];
        if(sum>max)
        {
            max=sum;
            l=start;
            r=i;
        }

        if(sum<0)
        {
            sum=0;
            start=i+1;
        }
    }
    fprintf(fp,"%d\n",max);
    fprintf(fp,"%d %d",l+1,r+1);
}

int main()
{
    FILE *fp1;
    FILE *fp2;

    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");

    int n;
    fscanf(fp1,"%d",&n);

    int i;
    int num[n];
    
    for(i=0;i<n;i++)
    {
        fscanf(fp1,"%d",&num[i]);
    }

    get_max(n,num,fp2);
}