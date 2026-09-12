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
ll mod;
struct matrix
{
  ll a[2][2];

    matrix()
    {
        memset(a,0,sizeof(a));
    }
};
matrix mul(matrix&A,matrix&B)
{
    matrix c;

    for(int i=0;i<2;i++)
    {
        for(int k=0;k<2;k++)
        {
            for(int j=0;j<2;j++)
            {
                c.a[i][j]=(c.a[i][j]%mod+(i128)A.a[i][k]*B.a[k][j]%mod)%mod;
            }
        }
    }

    return c;
}
matrix qpow(matrix&a,ll b)
{
    matrix res;
    for(int i=0;i<2;i++)
    {
        res.a[i][i]=1;
    }

    while(b)
    {
        if(b&1)res=mul(res,a);
        b>>=1;
        a=mul(a,a);
    }

    return res;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
ll p,q,a1,a2,n,m;
    cin>>p>>q>>a1>>a2>>n>>m;
    if(n==1)
    {
        cout<<a1%m<<endl;
        return 0;
    }
    mod=m;
    matrix ans;
    ans.a[0][0]=a2;
    ans.a[1][0]=a1;
    matrix pow;
    pow.a[0][0]=p;
    pow.a[0][1]=q;
    pow.a[1][0]=1;

    pow=qpow(pow,n-2);
    ans=mul(pow,ans);

    cout<<ans.a[0][0]<<endl;


    return 0;
}