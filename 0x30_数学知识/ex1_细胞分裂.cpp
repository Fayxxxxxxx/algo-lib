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

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
ll n,m1,m2;
    cin>>n>>m1>>m2;
    vll s(n);
    for(int i=0;i<n;i++)cin>>s[i];
    if(m1==1)
    {
        cout<<0<<endl;
        return 0;
    }
    vector<pll> nums;
    ll tmp=m1;
    for(ll p=2;p<=tmp/p;p++)
    {
        int cnt=0;
        if(tmp%p==0)
        {
            while(tmp%p==0)
            {
                cnt++;
                tmp/=p;
            }
            nums.push_back({p,cnt});
        }
    }
    if(tmp>1)
    {
        nums.push_back({tmp,1});
    }

    //分解完m1后进行分解s
    ll ans=LLONG_MAX;
    for(ll x:s)
    {
        bool flag=true;
        ll res=0;
        for(auto e:nums)
        {
            ll p=e.first;
            ll need=e.second*m2;

            ll cnt=0;

            while(x%p==0)
            {
                x/=p;
                cnt++;
            }

            if(cnt==0)
            {
                flag=false;
                break;
            }
            res=max(res,(need+cnt-1)/cnt);
        }
        if(flag)
        ans=min(ans,res);
    }
    if(ans==LLONG_MAX)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<ans<<endl;
    }



    return 0;
}   