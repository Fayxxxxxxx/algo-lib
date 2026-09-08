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
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
ll x,y,m,n,l;
cin>>x>>y>>m>>n>>l;

if(m==n&&x!=y)
{
    cout<<"Impossible"<<endl;
    return 0;
}


ll a=((m-n)%l+l)%l;
ll b=((y-x)%l+l)%l;

ll x1,y1;
ll d=exgcd(a,l,x1,y1);

if(b%d!=0)
{
    cout<<"Impossible"<<endl;
    return 0;
}
ll period=l/d;
x1=(i128)x1*b/d;

cout<<(x1%period+period)%period<<endl;

    return 0;
}