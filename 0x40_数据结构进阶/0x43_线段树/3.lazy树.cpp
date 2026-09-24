对于区间加和取区间和的问题 
我们采用lazy算法

也就是懒加 
整个节点都被修改区间完整覆盖时，我直接修改这个节点的信息，不急着修改下面所有叶子。
例如对于[1,4]+=2
那么对代表[1,4]的区间u来说 tr[u].add==2;
它并不是说 根节点以后还要+2 根节点已经加完了其实 它真正的含义是
这个节点代表的整个区间已经+2了 但是+2还没有告诉它的孩子

lazy tag
如果接下来问query[1,4]

需要pushdown吗？ 
不需要
因为根节点已经算对了

所以就是能不能就不下

如果实在问[1,2]

只要准备访问孩子 那就必须先看看父亲有没有欠孩子的修改
这就是pushdown(u)

pushdown 的过程中 孩子拿到这个add后 要把自己的add也改为2 因为根据传递性
其下面的其他孩子也要+=2 然后tr[u].add=0 父亲自己不欠了

lazy是一层一层欠债 不是一口气传到叶子

void apply(int u,int k)
{
    tr[u].sum+=k*(tr[u].r-tr[u].l+1);//要加多少？[1,4]加2 当然是加8
    tr[u].add+=k;//欠债款
}
void pushdown(int u)
{
    if(tr[u].add)
    {
        apply(u<<1,tr[u].add);
        apply(u<<1|1,tr[u].add);

        tr[u].add=0;
    }
}
void modify(int u,int l,int r,ll k)
{
  if(l<=tr[u].l&&tr[u].r<=r)
  {
    apply(u,k);
    return ;
  }

  pushdonw(u);
  int mid=(tr[u].l+tr[u].r)>>1;

  if(l<=mid)
  modify(u<<1,l,r,k);

  if(r>mid)
  modify(u<<1|1,l,r,k);

  pushup(u);


}










#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
using vc=vector<char>;
using vb=vector<bool>;
using vs=vector<string>;
using i128=__int128_t;
const int INF=0x3f3f3f3f;
const int N=2e5+5;
int n,m;
vll a(N);
struct node
{
    int l,r;
    ll sum;
    ll add;
}tr[N*4];
void pushup(int u)
{
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}
void apply(int u,ll k)
{
   tr[u].sum+=(tr[u].r-tr[u].l+1)*k;
   tr[u].add+=k;
}
void pushdown(int u)
{
    if(tr[u].add)
    {
        apply(u<<1,tr[u].add);
        apply(u<<1|1,tr[u].add);   

        tr[u].add=0;
    }
}

void build(int u,int l,int r)
{
    tr[u]={l,r,0,0};

    if(l==r)
    {
        tr[u].sum=a[l];
        return ;
    }

    int mid=(l+r)>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);

    pushup(u);
}
void modify(int u,int l,int r,ll k)
{
   if(l<=tr[u].l&&tr[u].r<=r)
   {
       apply(u,k);
       return ;
   }

    pushdown(u);
    int mid=(tr[u].l+tr[u].r)>>1;
    if(l<=mid)
    {
        modify(u<<1,l,r,k);
    }

    if(r>mid)
    {
       modify(u<<1|1,l,r,k);
    }
    pushup(u);
}

ll query(int u,int l,int r)
{
    if(l<=tr[u].l&&tr[u].r<=r)
    {
        return tr[u].sum;
    }
    pushdown(u);
    int mid=(tr[u].l+tr[u].r)>>1;

    ll res=0;

    if(l<=mid)res+=query(u<<1,l,r);

    if(r>mid)res+=query(u<<1|1,l,r);

    return res;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n>>m;
 for(int i=1;i<=n;i++)
 {
     cin>>a[i];
 }
    build(1,1,n);
    for(int i=0;i<m;i++)
    {
        int op;
        cin>>op;

        if(op==1)
        {
            int x,y;
            ll k;
            cin>>x>>y>>k;

            modify(1,x,y,k);
        }
        else
        {
            int x,y;
            cin>>x>>y;

            cout<<query(1,x,y)<<endl;
        }
    }



    return 0;
}
