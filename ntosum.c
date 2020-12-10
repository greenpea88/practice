#include <stdio.h>

int sum(int n,int total)
{
    if(n<=0) 
        return total;
    else
    {
        total+=n;
        n--;
        return sum(n,total);
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

    int total=sum(n,0);
    fprintf(fp2,"%d",total);
}