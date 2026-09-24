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
const int N=50;
int f[N][N];

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
f[1][0]=1;
    int n,m;
    cin>>n>>m;
    
    for(int k=1;k<=m;k++)
    {
     for(int i=1;i<=n;i++)
     {
         int l=(i==1?n:i-1);
        int r=(i==n?1:i+1);

         f[i][k]=f[l][k-1]+f[r][k-1];
     }
    }

    cout<<f[1][m]<<endl;


    return 0;
}