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


ll get_num(ll n,vector<pair<ll,int>>& fact)
{
    ll ans=1;
    for(auto [p,e]:fact)
    {
        ll sum=1;
        ll pw=1;

        for(int i=1;i<=e;i++)
        {
            pw*=p;
            sum+=pw;//1+p^2+p^3+......
        }//也可以写成等比数列求和的形式 但是如果太大要取模 那么还要处理逆元的事情

        ans*=sum;
    }
    return ans;
}


    