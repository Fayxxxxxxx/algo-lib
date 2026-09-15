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
const int N=2e5+10;
ll fa[N+5];
ll rk[N+5];
void init(int n)
{
for(int i=1;i<=n;i++)
{
 fa[i]=i;
 rk[i]=0;
} 
}

ll find(ll x)
{
    if(x==fa[x])return fa[x];

    return fa[x]=find(fa[x]);
}

void merge(ll x,ll y)
{
    ll fax=find(x);
    ll fay=find(y);

    if(fax==fay)return ;

    ll rx=rk[fax];
    ll ry=rk[fay];

    if(rx<ry)
    {
        swap(fax,fay);
    }

    fa[fay]=fax;

    if(rx==ry)
    {
        rk[fax]++;
    }
}

bool is_team(ll x,ll y)
{
    ll fx=find(x);
    ll fy=find(y);

    return fx==fy;
}
ll get(ll x,vector<ll>& nums)
{
 return (lower_bound(nums.begin(),nums.end(),x)-nums.begin())+1;
}
void solve()
{
    int n;
    cin>>n;
    
    vector<pair<ll,ll>> same;
    vector<pair<ll,ll>> no_same;
    vector<ll> nums;
    for(int k=0;k<n;k++)
    {
        ll i,j,e;
        cin>>i>>j>>e;
        nums.push_back(i);
        nums.push_back(j);
        if(e==1)
        {
            same.push_back({i,j});
        }
        else
        {
            no_same.push_back({i,j});
        }
    }
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    init((ll)nums.size());
    for(auto [x,y]:same)
    {
     merge(get(x,nums),get(y,nums));
    }

    for(auto [x,y]:no_same)
    {
        if(is_team(get(x,nums),get(y,nums)))
        {
            cout<<"NO"<<endl;
            return ;
        }
    }
    cout<<"YES"<<endl;

}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;
while(t--)
{
    solve();
}


    return 0;
}