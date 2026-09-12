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
void init(int n)
{
for(int i=1;i<=n;i++)fa[i]=i;
}
int find(int x)
{
   if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    x=find(x);
    y=find(y);

    if(x!=y)fa[x]=y;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n,m,p;
    cin>>n>>m>>p;
    init(n);
    for(int i=0;i<m;i++)
    {
        int m1,m2;
        cin>>m1>>m2;

        merge(m1,m2);
    }
    for(int i=0;i<p;i++)
    {
        int p1,p2;
        cin>>p1>>p2;

        p1=find(p1);
        p2=find(p2);

        if(p1!=p2)
        {
            cout<<"No"<<endl;
        }
        else
        {
            cout<<"Yes"<<endl;
        }
}


    return 0;
}