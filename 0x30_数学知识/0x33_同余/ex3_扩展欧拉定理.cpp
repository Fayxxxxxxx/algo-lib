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
ll qpow(ll a,ll b,ll mod)
{
    ll res=1;
    a%=mod;
    while(b)
    {
        if(b&1)res=(i128)res*a%mod;
        b>>=1;
        a=(i128)a*a%mod;
    }
    return res;
}
ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}
ll phi(ll n)
{
    ll ans=n;

    for(ll p=2;p<=n/p;p++)
    {
        if(n%p==0)
        {
            ans=ans/p*(p-1);
            while(n%p==0)
        {
            n/=p;
        }
        }
    }

    if(n>1){
        ans=ans/n*(n-1);
    }
    return ans;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
ll a,m;
string s;
cin>>a>>m>>s;
if(m==1)
{
    cout<<0<<endl;
    return 0;
}
ll b=0;
ll val=0;
bool big=false;
ll mod=phi(m);
for(char x:s)
{
    ll num=x-'0';
    b=((i128)b*10%mod+num)%mod;

    if(!big)
    {
        val=val*10+num;

        if(val>=mod)
        {
            big=true;
        }
    }
}
ll g=gcd(a,m);
ll q;
    if(g==1)
    {
        q=b;
    }
    else
    {
      if(big)
      {
          q=b+mod;
      }
    else
    {
       q=val;//真实的指数
    }
    }

    cout<<qpow(a,q,m)<<endl;
    



    return 0;
}