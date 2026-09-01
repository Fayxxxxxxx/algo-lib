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
const int INF=0x3f3f3f3f;
ll n,m;
vll nums;
int cnt1=0;
int cnt2=0;
vector<ll> left_;
vector<ll> right_;
void dfs1(ll total,int s,int e)
{
    if(total-m>0)return ;
    
    if(s==e)
    {
       left_.push_back(total);
        return ;
    }

    if(total+nums[s]<=m)dfs1(total+nums[s],s+1,e);

    dfs1(total,s+1,e);
}
void dfs2(ll total,int s,int e)
{
    if(total>m)return ;
    
    if(s==e)
    {
       right_.push_back(total);
        return ;
    }

    if(total+nums[s]<=m)dfs2(total+nums[s],s+1,e);

    dfs2(total,s+1,e);
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n>>m;
nums.resize(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    sort(nums.begin(),nums.end());

    while(!nums.empty()&&nums.back()>m)nums.pop_back();
    n=nums.size();
    dfs1(0,0,n/2);
    dfs2(0,n/2,n);

    sort(left_.begin(),left_.end());
    sort(right_.begin(),right_.end());
    ll ans=0;

    for(int i=0;i<left_.size();i++)
    {
        ll x=left_[i];

        int pos=(upper_bound(right_.begin(),right_.end(),m-x)-right_.begin());
        ans+=pos;
    }
    cout<<ans<<endl;

    return 0;
}