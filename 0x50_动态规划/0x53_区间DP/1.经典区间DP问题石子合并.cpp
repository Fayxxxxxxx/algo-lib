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
const int N=305;
int f[N][N];
int a[N];
int prefix[N];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n;
cin>>n;
memset(f,0x3f,sizeof f);
for(int i=1;i<=n;i++)
{
    cin>>a[i];
    f[i][i]=0;//单个当然没有合并的代价 而其他的我默认直接设置为0x3f
}

for(int i=1;i<=n;i++)
{
    prefix[i]=prefix[i-1]+a[i];
}
for(int len=2;len<=n;len++)//尤其是对len的考虑
{
    for(int i=1;i+len-1<=n;i++)
    {
        int j=i+len-1;
        
        for(int k=i;k<=j-1;k++)//k是左边块的右边界
        {
            f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+prefix[j]-prefix[i-1]);
        }
    }
}
cout<<f[1][n]<<endl;



    return 0;
}