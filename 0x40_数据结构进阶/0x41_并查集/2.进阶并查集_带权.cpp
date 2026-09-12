//现在不仅要问1和3是否在同一个集合的问题
//现在还想知道1到3相差多少的问题
//普通并查集这里 只有个fa[x]
//只表示x的父亲是谁
//现在再加一个d[x]
//表示从x到fa[x]的距离/关系

int find(int x)
{
    if(x==fa[x])return fa[x];

    int t=fa[x];
    fa[x]=find(fa[x]);
    d[x]+=d[t];

    return fa[x];
}

void merge(int x,int y)
{
我们定义d[x]=x-rx
x=rx+d[x]
则x-y=w
->d[x]+rx-(d[y]+ry)=w ->rx-ry=w+d[y]-d[x] ->fa[rx]=ry; d[rx]=w+d[y]-d[x]

int rx=find(x);
int ry=find(y);

if(rx!=ry)
{
    fa[rx]=ry;
    d[rx]=w+d[y]-d[x];
}
}