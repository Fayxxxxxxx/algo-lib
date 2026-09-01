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
int n,c;
vll nums;
vll prefix;
ll ans=0;
void dfs(ll total,int u)
{
 ans=max(ans,total);

    if(u<0)return ;

    if(prefix[u]+total<=ans)return ;

    if(prefix[u]+total<=c)
    {
        ans=max(ans,prefix[u]+total);
        return ;
    }

    if(total+nums[u]<=c)dfs(total+nums[u],u-1);

    dfs(total,u-1);
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n>>c;
nums.resize(n);
for(int i=0;i<n;i++)cin>>nums[i];
while(!nums.empty()&&nums.back()>c)
{
    nums.pop_back();
}
 n=nums.size();
    if(n==0)
    {
     cout<<0<<endl;
        return 0;
    }
prefix.resize(n);
prefix[0]=nums[0];
for(int i=1;i<n;i++){
    prefix[i]=prefix[i-1]+nums[i];
}
    
dfs(0,n-1);//个数是n 下标是n-1
cout<<ans<<endl;

    return 0;
}