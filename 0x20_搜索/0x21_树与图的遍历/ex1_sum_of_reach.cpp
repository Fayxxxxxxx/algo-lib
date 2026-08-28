#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int N=3e4+10;
bitset<N> f[N];
vi res;
vector<vi> g;
vi ind;
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n,m;
cin>>n>>m;
g.resize(n+1);
ind.resize(n+1);

for(int i=0;i<m;i++)
{
    int a,b;
    cin>>a>>b;

    g[a].push_back(b);
    ind[b]++;
}
queue<int> q;
for(int i=1;i<=n;i++)
{
    if(!ind[i])q.push(i);
}

while(!q.empty())
{
    int x=q.front();
    q.pop();

    for(int u:g[x])
    {
        ind[u]--;

        if(!ind[u])q.push(u);
    }

    res.push_back(x);
}

for(int i=(int)res.size()-1;i>=0;i--)
{
 int x=res[i];

 f[x][x]=1;

 for(int u:g[x]){
    f[x]|=f[u];
 }

}
for(int i=1;i<=n;i++)cout<<f[i].count()<<endl;


    return 0;
}