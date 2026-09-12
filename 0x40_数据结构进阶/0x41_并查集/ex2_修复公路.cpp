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
const int N=1e4;
int fa[N];
int n,m;
void init(int n)
{
    for(int i=1;i<=n;i++)fa[i]=i;
}
int find(int x)
{
    if(x==fa[x])return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    x=find(x);
    y=find(y);

    if(x!=y)
    {
        fa[x]=y;
        n--;
    }
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
    cin>>n>>m;
    init(n);
    vector<tuple<int,int,int>> vp(m);
    for(int i=0;i<m;i++)
    {
        int x,y,t;
        cin>>x>>y>>t;
        vp[i]={t,x,y};
    }

    sort(vp.begin(),vp.end());
    int time=0;
    for(int i=0;i<m;i++)
    {
        auto [t,x,y]=vp[i];
        merge(x,y);
        time=t;

        if(n==1)
      {
          cout<<time<<endl;
          return 0;
      }
    } 
    cout<<-1<<endl;


    return 0;
}