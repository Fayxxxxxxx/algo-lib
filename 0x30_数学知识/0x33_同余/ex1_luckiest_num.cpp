#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using i128=__int128_t;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
using vc=vector<char>;
using vb=vector<bool>;
using vs=vector<string>;

const int INF=0x3f3f3f3f;
const ll INFLL=0x3f3f3f3f3f3f3f3fLL;

ll qpow(ll a,ll b,ll mod)
{
    ll res=1;
    while(b)
    {
        if(b&1) res=(i128)res*a%mod;
        a=(i128)a*a%mod;
        b>>=1;
    }
    return res;
}

ll phi(ll n)
{
    ll ans=n;
    for(ll p=2;p<=n/p;p++)
    {
        if(n%p==0)
        {
            ans=ans/p*(p-1);
            while(n%p==0) n/=p;
        }
    }
    if(n>1) ans=ans/n*(n-1);
    return ans;
}

ll get_order(ll mod)
{
    if(__gcd(10LL,mod)!=1) return 0;
    
    ll ans=phi(mod);
    ll x=ans;
    
    for(ll p=2;p<=x/p;p++)
    {
        if(x%p==0)
        {
            while(ans%p==0 && qpow(10,ans/p,mod)==1)//得到余数 也是和自己同余的数
                ans/=p;
            while(x%p==0) x/=p;
        }
    }
    
    if(x>1)
    {
        ll p=x;
        while(ans%p==0 && qpow(10,ans/p,mod)==1)
            ans/=p;
    }
    
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll L;
    int T=1;
    
    while(cin>>L && L)
    {
        ll d=__gcd(8LL,L);
        ll mod=9LL*L/d;
        ll ans=get_order(mod);
        cout<<"Case "<<T++<<": "<<ans<<endl;
    }
    
    return 0;
}