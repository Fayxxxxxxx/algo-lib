int dist[N][N];
bool vis[N][N];]
queue<pii> q;
int arr[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

q.push({sx,sy});
vis[sx][sy]=1;
dist[sx][sy]=0;

while(!q.empty())
{
    auto [lx,ly]=q.top();
    q.pop();

    for(int i=0;i<4;i++)
    {
        int dx=lx+arr[i][0];
        int dy=ly+arr[i][1];

        if(!vis[dx][dy]&&dx>=1&&dy<=n)
        {
            dist[dx][dy]=dist[lx][ly]+1;
            vis[dx][dy]=1;
            q.push({dx,dy});    
        }
    }
}


void dfs(int x)
{
    a[++m]=x;
    v[x]=1;
    for(int i=head[x];i;i=next[i])
    {
        int y=ver[i];
        if(vis[y])continue;
        dfs(y);
    }
    a[++m]=x;
}

//求树的大小
void dfs(int x,int fa)
{
    siz[x]=1;

    for(auto y:g[x])
    {
        if(y==fa)continue;

        dfs(y,x);//注意是自底向上 先处理儿子 然后儿子递归上来 我再加上
        //也就是我想知道我的大小/树的高度 我得先知道我儿子的大小/高度 加上我自己
        //初始的大小/高度 就是我的大小/高度

        siz[x]+=siz[y];//所以是先向下dfs 然后再siz[x]+=siz[y]; 
    }
}

//树的重心 和最大连通块大小

所以删除 x 后最大连通块就是：

max(
    所有 siz[y],//其中siz[y] y是x的子树
    n-siz[x]
)

// //还有一种写法：直接判断是不是重心
// 根据性质：
// x 是重心
// ⇔ 删除 x 后每个连通块都 <= n/2
// 所以也可以写：
bool ok=1;
// 枚举孩子：
if(siz[y]>n/2)
    ok=0;
// 最后父亲方向：
if(n-siz[x]>n/2)
    ok=0;
// 如果：
// ok
// 那 x 就是重心。


//十三、树可能有几个重心？

一个树：

可能有 1 个重心，也可能有 2 个重心。

两个的时候它们一定相邻。


int ans=INT_MAX;
int best=0;

void dfs(int x)
{
    vis[x]=1;
    siz[x]=1;
    int mx=1;
    for(int i=head[x];i;i=next[i])
    {
        int y=ver[i];
        if(vis[y])continue;

        dfs(y);
        siz[x]+=siz[y];

        mx=max(mx,siz[y]);
    }
    mx=max(mx,n-siz[x]);

    if(mx<ans)
    {
        ans=mx;
        best=x;
    }
}

//用 n/2 判断
vi res;
void dfs(int x)
{
    vis[x]=1;
    siz[x]=1;
    bool ok=1;
    for(int i=head[x];i;i=next[i])
    {
        int y=ver[i];
        if(vis[y])continue;

        dfs(y);
        siz[x]+=siz[y];

        if(siz[y]>n/2)
        {
            ok=0;
        }
    }
    if(n-siz[x]>n/2)
    {
        ok=0;
    }

    if(ok)res.push_back(x);
}
int sz;
void dfs(int x)
{
 c[x]=cnt;//用来记录x节点是属于那个连通块的
 vis[i]=1;
 sz++;

 for(int i=head[x];i;i=nex[i])
 {
    int y=ver[i];

    if(vis[y])continue;

    dfs(y);
 }
}
bool vis[N];

for(int i=1;i<=n;i++)
{
 if(vis[i])continue;

 sz=0;
 dfs(i);
  cnt++;
 cout<<sz<<endl;
}

// 静态图 + 想知道连通块具体结构
// → DFS/BFS

// 动态合并 + 只关心是否属于同一集合
// → 并查集