#include <stdio.h>
#define MAX_N   5000

int node[MAX_N];

void get_node(FILE *fp,int n)
{
    int i;
    for(i=0;i<n;i++)
        fscanf(fp,"%d",&node[i]);
}

void find_theme(FILE *fp,int n)
{
    int i;
    int l,r,cnt;
    int max=0;
    for(i=5;i<n-5;i++)
    {
        cnt=1;
        for(l=0,r=l+i;r+1<n;l++,r++)
        {
            if(node[l+1]-node[l]==node[r+1]-node[r])
                cnt++;
            else
                cnt=1;

            if(cnt>max)
                max=cnt;

            if(cnt>i)
                break;
        }
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
    
    get_node(fp1,n);
    find_theme(fp2,n);
}