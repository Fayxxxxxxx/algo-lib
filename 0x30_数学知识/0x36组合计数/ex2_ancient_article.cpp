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
vll ds;
vll ps={2,3,4679,35617};
ll mod=999911659;
ll inner=999911658;
ll qpow(ll a,ll b,ll p)
{
    ll res=1;
    while(b)
    {
        if(b&1)res=(i128)res*a%p;
        b>>=1;
        a=(i128)a*a%p;
    }
    return res;
}
ll C(ll n,ll m,ll p)
{
    if(m>n)return 0;

    m=min(m,n-m);

    ll a=1;
    ll b=1;

    for(ll i=1;i<=m;i++)
    {
        a=a*(n-m+i)%p;
        b=b*(i)%p;
    }
    return a*qpow(b,p-2,p)%p;
}
ll lucas(ll n,ll m,ll p)
{
    if(m==0)return 1;

    return C(n%p,m%p,p)*lucas(n/p,m/p,p)%p;
}
ll exgcd(ll a,ll b,ll&x,ll& y)
{
    if(b==0)
    {
        x=1;
        y=0;

        return a;
    }

    ll x1,y1;
    ll dy=exgcd(b,a%b,x1,y1);

    x=y1;
    y=x1-a/b*y1;

    return dy;
}
ll inv(ll a,ll p)
{
    ll x,y;
    ll dy=exgcd(a,p,x,y);

    return (x%p+p)%p;
}
ll crt(vll nums)
{
    ll M=1;
    for(ll x:ps)
    {
        M*=x;
    }
    ll ans=0;
    for(int i=0;i<4;i++)
    {
        ll mi=M/ps[i];
        ll ti=inv(mi%ps[i],ps[i]);
        ans=(ans%inner+(i128)ti*mi*nums[i]%inner)%inner;
    }
    return (ans%inner+inner)%inner;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
ll n,g;
    cin>>n>>g;
    if(g%999911659==0)
    {
        cout<<0<<endl;
        return 0;
    }
    //1.把n进行分解
    for(int i=1;i<=n/i;i++)
    {
        if(n%i==0)
        {
             if(i!=n/i)
        {
           ds.push_back(i);
        }
            ds.push_back(n/i);
        }
    }
    //得到了n的所有约数d
    vll nums(4);
    for(int i=0;i<4;i++)
    {
        ll p=ps[i];

        ll res=0;
        for(ll d:ds)
        {
            res=(res%p+lucas(n,d,p)%p)%p;
        }
        nums[i]=res;
    }
    ll P=crt(nums);

    cout<<qpow(g,P,mod)<<endl;
    

    return 0;
}