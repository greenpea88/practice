#include <stdio.h>

int return_money(int money)
{
    int r[8]={5000,1000,500,100,50,10,5,1};

    int i;
    int cnt=0;
    for(i=0;i<8;i++)
    {
        if(r[i]<=money)
        {
            cnt+=money/r[i];
            money-=r[i]*(money/r[i]);
        }
    }

    return cnt;
}

int main()
{
    FILE *fp1;
    FILE *fp2;

    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");

    int m;
    fscanf(fp1,"%d",&m);
    
    fprintf(fp2,"%d",return_money(m));
}