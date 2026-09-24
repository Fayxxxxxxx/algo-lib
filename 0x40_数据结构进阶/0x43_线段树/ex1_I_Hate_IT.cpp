//查找最大值
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
vll nums(N);
int n,m;
struct node
{
  int l,r;
  ll sum;
  ll mx;
}tr[N*4];
void pushup(int u)
{
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
    tr[u].mx=max(tr[u<<1].mx,tr[u<<1|1].mx);
}
void build(int u,int l,int r)
{
    tr[u]={l,r,0,0};

    if(l==r)
    {
        tr[u].sum=nums[l];
        tr[u].mx=nums[l];
        return ;
    }
    int mid=(l+r)>>1;

    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);

    pushup(u);
}
void add(int u,int x,ll k)
{
    if(tr[u].l==tr[u].r)
    {
        tr[u].sum+=k;
        tr[u].mx+=k;
        return ;
    }

    int mid=(tr[u].l+tr[u].r)>>1;

    if(mid>=x)
    {
        add(u<<1,x,k);
    }
    else
    {
      add(u<<1|1,x,k);
    }

    pushup(u);
}
ll query(int u,int l,int r)
{
    if(tr[u].l>=l&&tr[u].r<=r)
    {
        return tr[u].mx;
    }

    int mid=(tr[u].l+tr[u].r)>>1;

    ll res=0;

    if(l<=mid)
    {
        res=max(res,query(u<<1,l,r));
    }
    if(r>mid)
    {
        res=max(res,query(u<<1|1,l,r));
    }

    return res;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>nums[i];
    build(1,1,n);
   for(int i=0;i<m;i++){
       char op;
       int a,b;
       cin>>op>>a>>b;
       
       if(op=='Q')
       {
           cout<<query(1,a,b)<<endl;
       }
       else
       {
         if(nums[a]<b)
         {
             add(1,a,b-nums[a]);
             nums[a]=b;
         }
       }
   }


    return 0;
}


//下面是修改版本

//查找最大值
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
vll nums(N);
int n,m;
struct node
{
  int l,r;
  ll mx;
}tr[N*4];
void pushup(int u)
{
    tr[u].mx=max(tr[u<<1].mx,tr[u<<1|1].mx);
}
void build(int u,int l,int r)
{
    tr[u]={l,r,0};

    if(l==r)
    {
        tr[u].mx=nums[l];
        return ;
    }
    int mid=(l+r)>>1;

    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);

    pushup(u);
}
void modify(int u,int x,ll k)
{
    if(tr[u].l==tr[u].r)
    {
        if(tr[u].mx<k)
        {
            tr[u].mx=k;
            nums[x]=k;
        }
        return ;
    }

    int mid=(tr[u].l+tr[u].r)>>1;

    if(mid>=x)
    {
        modify(u<<1,x,k);
    }
    else
    {
      modify(u<<1|1,x,k);
    }

    pushup(u);
}
ll query(int u,int l,int r)
{
    if(tr[u].l>=l&&tr[u].r<=r)
    {
        return tr[u].mx;
    }

    int mid=(tr[u].l+tr[u].r)>>1;

    ll res=0;

    if(l<=mid)
    {
        res=max(res,query(u<<1,l,r));
    }
    if(r>mid)
    {
        res=max(res,query(u<<1|1,l,r));
    }

    return res;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>nums[i];
    build(1,1,n);
   for(int i=0;i<m;i++){
       char op;
       int a,b;
       cin>>op>>a>>b;
       
       if(op=='Q')
       {
           cout<<query(1,a,b)<<endl;
       }
       else
       {
        modify(1,a,b);
       }
   }


    return 0;
}