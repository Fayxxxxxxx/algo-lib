#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int N=100000*32;
int son[N][2];
int idx;
void insert(int x)
{
    int u=0;
    for(int i=30;i>=0;i--)
    {
        int bit=(x>>i)&1;
        if(!son[u][bit])
        {
            son[u][bit]=++idx;
        }
        u=son[u][bit];
    }
}
int query(int x)
{
    int u=0;
    int res=0;
    for(int i=30;i>=0;i--)
    {
        int bit=(x>>i)&1;
        if(son[u][bit^1])
        {
            u=son[u][bit^1];
            res|=(1<<i);
        }
        else
        {
            u=son[u][bit];
        }
    }
    return res;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n;
cin>>n;
vector<vector<pll>> g(n);
vll d(n);
for(int i=0;i<n-1;i++)
{
    ll x,y,w;
    cin>>x>>y>>w;
    g[x].push_back({y,w});
    g[y].push_back({x,w});
}
queue<int> q;
vi fa(n,-1);
fa[0]=-2;
q.push(0);
while(q.size())
{
    int u=q.front();
    q.pop();
    
    for(auto [v,w]:g[u])
    {
    if(fa[v]!=-1)
    continue;
    
    fa[v]=u;
    d[v]=d[u]^w;
    
    q.push(v);
    }
}
int ans=0;
for(int i=0;i<n;i++)
{
    if(i>0)
    {
        ans=max(ans,query(d[i]));
    }
    insert(d[i]);
}

cout<<ans<<endl;




    return 0;
}