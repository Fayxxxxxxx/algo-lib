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
const int N=3e4;
int d[N+5]={};
int fa[N+5];
int sz[N+5]={};
void init()
{
   for(int i=1;i<=N;i++)
   {
       fa[i]=i;
       sz[i]=1;
   }
}
int find(int x)
{
    if(x==fa[x])return fa[x];

    int t=fa[x];
    fa[x]=find(fa[x]);
    d[x]+=d[t];

    return fa[x];
}
void merge(int x,int y)
{
    int rx=find(x);
    int ry=find(y);

    if(rx!=ry)
    {
        fa[rx]=ry;
        d[rx]=sz[ry];
        sz[ry]+=sz[rx];
    }
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int t;
    cin>>t;
    init();
    while(t--)
    {
        char op;
        int i,j;
        cin>>op>>i>>j;

        if(op=='M')
        {
            merge(i,j);
        }
        else
        {
            int x=find(i);
            int y=find(j);

            if(x==y)
            {
                cout<<abs(d[i]-d[j])-1<<endl;
            }
            else
            {
             cout<<-1<<endl;
            }
        }

        
    }


    return 0;
}