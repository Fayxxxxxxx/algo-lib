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
const int N=5e4+5;
int fa[N];
int d[N];

void init()
{
    for(int i=0;i<N;i++)
    {
        fa[i]=i;
    }
}
int find(int x)
{
    if(x==fa[x])return fa[x];
    int t=fa[x];
    fa[x]=find(fa[x]);
    d[x]=(d[x]+d[t])%3;
    return fa[x];
}
void merge(int x,int y,int need)
{
    int rx=find(x);
    int ry=find(y);

    if(rx==ry)return ;

    fa[rx]=ry;
    d[rx]=(need-d[x]+d[y]+3)%3;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
init();
int n,k;
cin>>n>>k;
int cnt=0;
for(int i=0;i<k;i++)
{
    int D,x,y;
    cin>>D>>x>>y;
    if(x>n||y>n)
    {
        cnt++;
        continue;
    }
    if(D==2&&x==y)
    {
        cnt++;
        continue;
    }
    int need;

    if(D==1)
    {
        need=0;
    }
    else
    {
        need=1;
    }
    
    int rx=find(x);
    int ry=find(y);

    if(rx==ry)//两个已经是同一类了
    {
       if(need!=(d[x]-d[y]+3)%3)
       {
        cnt++;
       }
    }
    else
    { 
      merge(x,y,need);
    }
}
cout<<cnt<<endl;


    return 0;
}