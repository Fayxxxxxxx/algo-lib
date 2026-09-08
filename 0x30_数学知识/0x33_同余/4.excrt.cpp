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

bool merge(ll& A,ll& M,ll a,ll m)
{
    //x===A(mod M);
    //x===a(mod m);

    ll x,y;

    ll d=exgcd(M,m,x,y);
    
    ll c=a-A;

    if(c%d!=0)
    {
        return false;
    }

    ll mod=m/d;
    ll k=(i128)x*(c/d)%mod;
    k=(k%mod+mod)%mod;

    A=A+(i128)M*k;//x

    M=M/d*m;///lcm(M,m) 两数相乘再除以最大公约数

    A=(A%M+M)%M;

    return true;
}

ll excrt(vll& a,vll& m)
{
    int n=a.size();

    ll A=a[0];
    ll M=m[0];

    A=(A%M+M)%M;

    for(int i=1;i<n;i++)
    {
        if(!merge(A,M,a[i],m[i]))
        {
            return -1;
        }
    }

    return A;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n;
cin>>n;

vll a(n),m(n);

for(int i=0;i<n;i++)
{
    cin>>a[i]>>m[i];
}


cout<<excrt(a,m)<<endl;
    return 0;
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
    ll d=exgcd(b,a%b,x1,y1);

    x=y1;
    y=x1-a/b*y1;

    return d;
}
bool merge(ll&A,ll&M,ll a,ll m)
{
    ll x,y;

    ll d=exgcd(M,m,x,y);

    ll c=a-A;

    if(d%c!=0)
    {
        return false;
    }

    ll period=m/d;

    ll k=(i128)x*(c/d)%period;
    k=(k%period+period)%period;

    A=(i128)M*k+A;
    M=M/d*m;

    A=(A%M+M)%M;//然后还要再约

    return true;
}