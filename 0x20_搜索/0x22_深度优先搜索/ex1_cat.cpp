#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int N=20;
ll car[N];
int ans=INT_MAX;
ll n,w;
vll nums;
void dfs(int u,int cnt)
{
if(cnt>=ans)return ;
if(u==n)
{
    ans=min(ans,cnt);
    return ;
}
//选择旧车
for(int i=0;i<cnt;i++)
{
    if(nums[u]+car[i]>w)continue;
    car[i]+=nums[u];
    dfs(u+1,cnt);
    car[i]-=nums[u];
}

//选择新车
car[cnt]=nums[u];
dfs(u+1,cnt+1);
car[cnt]=0;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n>>w;
nums.resize(n);
for(int i=0;i<n;i++)cin>>nums[i];
sort(nums.begin(),nums.end(),greater<ll>());
dfs(0,0);

cout<<ans<<endl;


    return 0;
}