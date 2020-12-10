#include <stdio.h>
#define MAX_N   20

struct lecture
{
    int num;
    int start;
    int end;
    int selected;
};

struct lecture lc[MAX_N];

void sort(int n)
{
    int i,j;

    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(lc[i].end>lc[j].end)
            {
                struct lecture tmp=lc[j];
                lc[j]=lc[i];
                lc[i]=tmp;
            }
        }
    }
}

int select_lecture(int n)
{
    int finish=0;
    int i;
    int selected_num=0;
    for(i=0;i<n;i++)
    {
        if(finish<=lc[i].start)
        {
            lc[i].selected=1;
            finish=lc[i].end;
            selected_num++;
        }
    }
    return selected_num;
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
    
    for(i=0;i<n;i++)
    {
        fscanf(fp1,"%d %d %d",&lc[i].num,&lc[i].start,&lc[i].end);
    }

    sort(n);
    fprintf(fp2,"%d\n",select_lecture(n));

    for(i=0;i<n;i++)
    {
        if(lc[i].selected==1)
            fprintf(fp2,"%d ",lc[i].num);
    }
    
}