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
struct node
{
    ll x;
    ll y;
    string op;
};
const int N=1e4+5;
int fa[N];
int d[N]={};
void init(){
  for(int i=0;i<N;i++)
  {
    fa[i]=i;
  }
}
ll find(ll x)
{
    if(x==fa[x])return fa[x];

    ll t=fa[x];
    fa[x]=find(fa[x]);
    d[x]^=d[t];

    return fa[x];
}
ll get(ll x,vector<ll>&nums)
{
    return (ll)(lower_bound(nums.begin(),nums.end(),x)-nums.begin());
}
void merge(ll x,ll y,ll w)
{
    ll rx=find(x);
    ll ry=find(y);

    if(rx!=ry)
    {
        d[rx]=d[x]^d[y]^w;
        fa[rx]=ry;
    }
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
ll n,m;
cin>>n>>m;

vector<node> link;
vector<ll> nums;
for(int i=0;i<m;i++)
{
    ll x,y;
    string op;
    cin>>x>>y>>op;
    nums.push_back(x-1);//这里对prefix的抽象化有点难理解说实话
    nums.push_back(y);
    link.push_back({x,y,op});
}

sort(nums.begin(),nums.end());
nums.erase(unique(nums.begin(),nums.end()),nums.end());
//离散化
init();
int t=1;
for(auto [x,y,op]:link)
{
    ll u=get(x-1,nums);
    ll v=get(y,nums);

   ll rx=find(u);
   ll ry=find(v);

   if(rx==ry)
   {
     if((d[u]^d[v])!=(op=="even"?0:1))
     {
        cout<<t-1<<endl;
        return 0;
     }
   }
   else
   {
    merge(u,v,(op=="even"?0:1));
   }
   t++;

  
}
 cout<<m<<endl;
    return 0;
}