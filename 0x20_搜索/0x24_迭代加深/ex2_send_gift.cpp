#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
vll A,B;
int n,w;
vll nums;
void dfs1(int start,ll sum,int end)
{
    if(sum>w)return ;
    
    if(start==end)
    {
        A.push_back(sum);
        return ;
    }
    
    dfs1(start+1,sum,end);
    if(sum+nums[start]<=w)
    dfs1(start+1,sum+nums[start],end);
}
void dfs2(int start,ll sum,int end)
{
    if(sum>w)return ;
    
    if(start==end)
    {
        B.push_back(sum);
        return ;
    }
    
    dfs2(start+1,sum,end);
    if(sum+nums[start]<=w)
    dfs2(start+1,sum+nums[start],end);
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>w>>n;
nums.resize(n);
for(int i=0;i<n;i++)cin>>nums[i];
sort(nums.begin(),nums.end());
dfs1(0,0,n/2);
dfs2(n/2,0,n);
ll ans=0;
sort(B.begin(),B.end());
sort(A.begin(),A.end());
A.erase(unique(A.begin(),A.end()),A.end());
B.erase(unique(B.begin(),B.end()),B.end());
for(ll x:A)
{
    int pos=(upper_bound(B.begin(),B.end(),w-x)-B.begin())-1;
    
    if(pos>=0)
    ans=max(ans,x+B[pos]);
}
cout<<ans<<endl;

    return 0;
}