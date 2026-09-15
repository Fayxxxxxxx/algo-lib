const int N=1e5;
int fa[N];
int rk[N];

void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
        rk[i]=0;
    }
}
int find(int x)
{
    if(x==fa[x])return fa[x];

    return fa[x]=find(fa[x]);
}

void merge(int x,int y)
{
    int fx=find(x);
    int fy=find(y);

    if(fx==fy)return ;

    int rx=rk[fx];
    int ry=rk[fy];

    if(rx>ry)
    {
        swap(rx,ry);
    }

    //此时ry大
    fa[fx]=fy;//都默认挂在y上好了

    if(rx==ry)//只有两个树高度相同 且有一颗树必须要挂在另一棵树下 则高度+1
    {
        rk[fy]++;
    }

}