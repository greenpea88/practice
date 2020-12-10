#include <stdio.h>
#define MAX_N   100

int map[MAX_N][MAX_N];

void get_map(FILE *fp,int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            fscanf(fp,"%d",&map[i][j]);
    }
}

void get_best(FILE *fp,int n)
{
    int top,bot;
    int li,lj,ri,rj,j;
    int start,sum;
    int best=-99;
    int arr[n];

    for(top=0;top<n;top++)
    {
        for(j=0;j<n;j++)
            arr[j]=0;
        for(bot=top;bot<n;bot++)
        {
            for(j=0;j<n;j++)
                arr[j]+=map[bot][j];
            
            start=sum=0;
            for(j=0;j<n;j++)
            {
                sum+=arr[j];
                if(sum>best)
                {
                    best=sum;
                    li=top;
                    lj=start;
                    ri=bot;
                    rj=j;
                }

                if(sum<0)
                {
                    sum=0;
                    start=j+1;
                }
            }
            
        }
    }

    fprintf(fp,"%d\n",best);
    fprintf(fp,"%d %d %d %d",lj+1,li+1,rj+1,ri+1);
}

int main()
{
    FILE *fp1;
    FILE *fp2;

    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");

    int n;
    fscanf(fp1,"%d",&n);
    get_map(fp1,n);
    get_best(fp2,n);
}