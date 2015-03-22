#include<stdio.h>
#define M 51
int g[M][M],cs[M],ans[M],now[M];
int re;
int flag;

void dfs(int n,int depth,int *u)
{
    int i,j,k,v[M],vn;
    if(n)
    {
        if(depth+cs[u[0]]<=re)
            return;
        for(i=0;i<n+depth-re;i++)
        {
            for(j=i+1,vn=0;j<n;j++)
                if(g[u[i]][u[j]])
                    v[vn++]=u[j];
            now[depth]=u[i];
            dfs(vn,depth+1,v);
            if(flag)
                return;
        }
    }
    else if(depth>re)
    {
        re=depth;
        flag= 1;
        for(i=0;i<depth;i++)
            ans[i]=now[i];
    }
}

int clique(int n)
{
    int vn,v[M],i,j,k;
    re=0;
    for(cs[i=n-1];i>=0;i--)
    {
        for(vn=0,j=i+1;j<n;j++)
            if(g[i][j])
                v[vn++]=j;
        flag= 0;
        now[0]=i;
        dfs(vn,1,v);
        cs[i]=re;
    }
    return re;
}
//////////////////////////////////////
int main()
{
    int n;
    int i;
    int j;
    while(scanf("%d",&n),n)
    {
        for(i =0;i<n;i++)
            for(j =0;j<n;j++)
                scanf("%d",&g[i][j]);
        printf("%d\n",clique(n));
    }
    return 0;
}
