#include <stdio.h>
#define MAX_N   100

char mine_table[MAX_N+2][MAX_N+2];
int hint[MAX_N][MAX_N];

int di[8]={-1,-1,0,1,1,1,0,-1};
int dj[8]={0,1,1,1,0,-1,-1,-1};

void get_table(FILE *fp,int n,int m)
{
    int i;
    int j=1;
    for(i=1;i<n+1;i++)
    {
        fscanf(fp,"%s",&mine_table[i][j]);
    }
}

void get_hint(int n,int m)
{
    int i,j,x;
    for(i=1;i<n+1;i++)
    {
        for(j=1;j<m+1;j++)
        {
            if(mine_table[i][j]=='*') continue;
            int mine_cnt=0;
            for(x=0;x<8;x++)
            {
                if(mine_table[i+di[x]][j+dj[x]]=='*')
                    mine_cnt++;
            }
            hint[i][j]=mine_cnt;
        }
    }
}

int main()
{
    FILE *fp1;
    FILE *fp2;

    fp1=fopen("input.txt","r");
    fp2=fopen("ouput.txt","w");

    int n,m;
    fscanf(fp1,"%d %d",&n,&m);
    get_table(fp1,n,m);
    get_hint(n,m);

    int i,j;
    for(i=1;i<n+1;i++)
    {
        for(j=1;j<m+1;j++)
        {
            if(mine_table[i][j]=='*') fprintf(fp2,"%c",'*');
            else    fprintf(fp2,"%d",hint[i][j]);
        }
        fprintf(fp2,"\n");
    }

}