//中国剩余定理不能用这道题 m没有两两互质
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
ll exgcd(ll a,ll b,ll&x,ll&y)
{
    if(b==0)
    {
        x=1;
        y=0;

        return a;
    }

    ll x1,y1;
    ll d=exgcd(b,a%b,x1,y1);

    x=y1;
    y=x1-a/b*y1;

    return d;
}
ll inv(ll a,ll mod)
{
    ll x,y;
    
    ll d=exgcd(a,mod,x,y);

    if(d!=1)return -1;

    return (x%mod+mod)%mod;
}
ll crt(vll& a,vll& m,int n)
{
    ll M=1;
    for(int i=0;i<n;i++)
    {
        M*=m[i];
    }
    
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        ll mi=M/m[i];

        ll ti=inv(mi%m[i],m[i]);
        if(ti==-1)
        {
            return -1;
        }

        ans=(ans%M+(i128)mi*ti*a[i]%M)%M;
    }
    return (ans%M+M)%M;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n;
cin>>n;
vll a(n);
vll m(n);

for(int i=0;i<n;i++)cin>>a[i];
for(int i=0;i<n;i++)cin>>m[i];

cout<<crt(a,m,n);



    return 0;
}





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
ll exgcd(ll a,ll b,ll&x,ll& y)
{
    if(b==0)
    {
        x=1;
        y=0;

        return a;
    }

    ll x1,y1;
    ll d=exgcd(b,a%b,x1,y1);

    x=y1;
    y=x1-a/b*y1;

    return d;
}
ll inv(ll a,ll mod)
{
    ll x,y;
    ll d=exgcd(a,mod,x,y);

    if(d!=1)
    {
        return -1;
    }

    return (x%mod+mod)%mod;
}
ll crt(vll&a,vll&m)
{
   ll M=1;

   for(ll x:m)
   {
     M*=b;
   }

   ll ans=0;

   for(int i=0;i<a.size();i++)
   {
    ll mi=M/b[i];

    ll ti=inv(mi%m[i],m[i]);
    if(ti==-1)
    {
        return -1;
    }
    ans=(ans%M+(i128)ti*mi*a[i]%M)%M;
   }

   return (ans%M+M)%M;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
ll n;
cin>>n;

vll a(n);
vll m(n);

for(int i=0;i<n;i++){
    cin>>a[i]>>m[i];
}





    return 0;
}