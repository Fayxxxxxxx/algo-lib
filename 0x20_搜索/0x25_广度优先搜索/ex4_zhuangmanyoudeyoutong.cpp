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
using state=tuple<int,int,int>;//cost city fuel
const int INF=0x3f3f3f3f;
int n,m;
vector<vector<pii>> g;
vi prices;
int dijkstra(int c,int s,int e)
{
  vector<vi> dist(n+1,vi(c+1,INF));
  priority_queue<state,vector<state>,greater<state>> pq;
  dist[s][0]=0;
  pq.push({0,s,0});

  while(!pq.empty())
  {
    auto [cost,u,fuel]=pq.top();
    pq.pop();

    if(dist[u][fuel]!=cost)continue;

    if(u==e)return cost;

    if(fuel<c)
    {
        int new_cost=cost+prices[u];

        if(new_cost<dist[u][fuel+1])
        {
            dist[u][fuel+1]=new_cost;
            pq.push({new_cost,u,fuel+1});
        }
    }

    for(auto [v,w]:g[u])
    {
        if(fuel<w)continue;

        if(dist[v][fuel-w]>cost)
        {
            dist[v][fuel-w]=cost;
            pq.push({cost,v,fuel-w});
        }
    }
  }
  return -1;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n>>m;
prices.resize(n);
for(int i=0;i<n;i++)cin>>prices[i];
g.resize(n+1);
for(int i=0;i<m;i++)
{
    int u,v,d;
    cin>>u>>v>>d;

    g[u].push_back({v,d});
    g[v].push_back({u,d});
}

int q;
cin>>q;
while(q--)
{
    int c,s,e;
    cin>>c>>s>>e;
    int ans=dijkstra(c,s,e);

    if(ans==-1)
    {
        cout<<"impossible"<<endl;
    }
    else
    {
        cout<<ans<<endl;
    }
}

    return 0;
}