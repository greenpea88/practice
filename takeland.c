#include <stdio.h>
#define MAX_N   100

int map[MAX_N][MAX_N];

void get_map(FILE *fp,int n,int m)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            fscanf(fp,"%d",&map[i][j]);
        }
    }
}

void get_largest(FILE *fp,int n,int m)
{
    int top,bot,j;
    int best=0;
    int max,cnt;
    int arr[m];

    for(top=0;top<n;top++)
    {
        for(j=0;j<m;j++)
            arr[j]=0;
        for(bot=top;bot<n;bot++)
        {
            for(j=0;j<m;j++)
                arr[j]|=map[bot][j];

            max=cnt=0;
            for(j=0;j<m;j++)
            {
                if(arr[j]==0)
                    cnt++;
                else
                    cnt=0;
                
                if(max<cnt)
                    max=cnt;
            }
            if (best<(bot-top+1)*max)
				best=(bot-top+1)*max;
        }
    }

    fprintf(fp,"%d",best);
}

int main()
{
    FILE *fp1;
    FILE *fp2;

    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");

    int n,m;
    fscanf(fp1,"%d %d",&n,&m);
    get_map(fp1,n,m);
    get_largest(fp2,n,m);
}