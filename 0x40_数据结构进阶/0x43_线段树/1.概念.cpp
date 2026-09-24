把所有区间的值都提前的存储起来 知道每一个值成为一个区间 然后去进行运算
用到类似二叉树的思想 每一个父节点[l,r]拆成 [l,mid]+[mid+1,r] 
然后最后一层都是被查为类似[l,l]的元节点（叶子）

四个基本操作
build:建树
pushup:父节点由儿子更新
modify:单点修改
query:区间查询

1.定节点
struct Node
{
int l,r;
ll sum;
};

Node tr[N*4]//四倍树
tr[u]表示线段树编号为u的节点 它维护[l,r]这一段的信息

2.儿子编号怎么写
如果当前节点编号为u

那么其左儿子编号为 u<<1;
右儿子为u<<1|1

u*2 u*2+1

3.pushup

void pushup(int u)
{
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;  

    //以后如果维护最大值

    tr[u].mx=max(tr[u<<1].mx,tr[u<<1|1].mx);
}

4.build怎么写
假设原数组 ll a[N];

void build(int u,int l,int r)
{
    tr[u]={l,r,0};

    if(l==r)
    {
        tr[u].sum=a[l];
        return ;
    }

    int mid=(l+r)>>1;

    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);

    pushup(u);//这里把值加回来千万别忘了！！！！！
}

调用build(1,1,n);


5.单点修改
把a[x]+=k

void modify(int u,int x,ll k)
{
    if(tr[u].l==tr[u].r)
    {
        tr[u].sum+=k;
        return ;
    }

    int mid=(tr[u].l+tr[u].r)>>1;

    if(x<=mid)
    {
        modify(u<<1,x,k);
    }
    else
    {
        modify(u<<1|1,x,k);
    }
    pushup(u);//把值加上来！！ 不会重复计算
    因为pushup是之间覆盖修改
}
调用 modify(1,x,k);
6.区间查询
问[l,r]的值

ll query(int u,int l,int r)
{
if(l<=tr[u].l&&tr[u].r<=r)
{
    return tr[u].sum;
}
int mid=(tr[u].l+tr[u].r)>>1;

ll res=0;

if(l<=mid)res+=query(u<<1,l,r);
if(r>mid)res+=query(u<<1|1,l,r);

return res;
}
cout<<query(1,l,r)<<endl;