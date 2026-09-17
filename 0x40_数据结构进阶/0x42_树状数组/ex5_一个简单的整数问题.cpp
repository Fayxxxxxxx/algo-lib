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
const int N=2e5+5;
ll tr[N];
int n,m;
void add(ll x,ll k)
{
    while(x<=n)
    {
        tr[x]+=k;
        x+=x&-x;
    }
}
ll query(ll x)
{
    ll res=0;
    while(x)
    {
     res+=tr[x];
     x-=x&-x;
    }
    return res;
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n>>m;
vll nums(n+1);
vll diff(n+1);

for(int i=1;i<=n;i++)
{
    cin>>nums[i];
    diff[i]=nums[i]-nums[i-1];
}
for(int i=1;i<=n;i++)
{
    add(i,diff[i]);
}
for(int i=0;i<m;i++)
{
     char op;
     cin>>op;

     if(op=='C')
     {
        ll l,r,d;
        cin>>l>>r>>d;

        add(l,d);
        add(r+1,-d);
     }
     else
     {
        ll x;
        cin>>x;
        cout<<query(x)<<endl;
     }
}
    return 0;
}