///实际上f[i][j]的树形和状态 都和01背包是相同的 
//实际上就是对选几个的问题进行讨论
//即f[i][j]=max(f[i-1][j],f[i-1][j-v[i]]+w,f[i-1][j-2*v[i]]+2*w)........
//而观察发现f[i][j-v[i]]=max(f[i-1][j-v[i]],f[i-1][j-2*v[i]]+w....)

//所以也就是f[i][j]=max(f[i-1][j],f[i][j-v[i]]+w);
//且观察发现 其值必须需要这一层的 所以必须从小到大
//且从v[i]开始

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
const int N=1010;
int v[N],w[N];
int f[N];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n,m;
cin>>n>>m;
for(int i=1;i<=n;i++)cin>>v[i]>>w[i];

for(int i=1;i<=n;i++)
{
    for(int j=v[i];j<=m;j++)//从小到大的原因是我需要的是这一层小的那个值
    {
        f[j]=max(f[j],f[j-v[i]]+w[i]);
    }
}
cout<<f[m]<<endl;



    return 0;
}