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
const int INF=0x3f3f3f3f;

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
ll n,k;
cin>>n>>k;

ll ans=n*k;

for(ll l=1,r;l<=min(n,k);l=r+1)
{
    ll p=n/l;

    r=n/p;

    ans-=(l+r)*(r-l+1)/2;
}

cout<<ans<<endl;



    return 0;
}