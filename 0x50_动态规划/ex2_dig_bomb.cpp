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
int ans;
map<int,vi> mp;
vb vis;
vi path;
vi p_ans;
void dfs(int cur,int total,vi&nums)//从哪里开始
{
 if(total>ans)
 {
     p_ans=path;
     ans=total;
 }
    for(auto id:mp[cur])
    {
        if(id>cur&&!vis[id])
        {
            vis[id]=true;
            path.push_back(id);
            dfs(id,total+nums[id],nums);
            vis[id]=false;
            path.pop_back();
        }
    }
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n;
    cin>>n;
    vis.resize(n+1);
    vector<int> bomb(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>bomb[i];
    }
    
    int tt=1;
    for(int j=n-1;j>=1;j--)
    {
        for(int i=1;i<=j;i++)
        {
            int op;
            cin>>op;

            if(op)
            {
             mp[tt].push_back(tt+i);
            }
        }
        tt++;
    }
    for(int i=1;i<=n;i++)
    {
        path.push_back(i);
        dfs(i,bomb[i],bomb);
        path.pop_back();
    }
    for(int x:p_ans)cout<<x<<" ";
    cout<<endl;
   cout<<ans<<endl;
    return 0;
}



//dp写法  不妨设dp[i] 为以i为结尾的最大地雷数
//那么对于一个i而言 我要么是去遍历前面的dp[j]然后dp[j]+a[i] 要么就是从此开始就是a[i]
//并且我需要一个pre[i] 用来记录每个i 是由哪里走过来的 也就是在更新dp的时候记录  

#include<bits/stdc++.h>//对于此类传递性问题 我们需要设dp[i]为以i为结尾或者以i为起点等等等等
//这样才有传递性
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
const int N=25;
int lik[N][N];
int dp[N];
int pre[N];
int a[N];

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n;
cin>>n;

for(int i=1;i<=n;i++)cin>>a[i];

for(int i=1;i<=n;i++)
{
    int len=n-i;
    for(int j=1;j<=len;j++)
    {
        int op;
        cin>>op;

        if(op)lik[i][i+j]=1;
    }
}
for(int i=1;i<=n;i++)dp[i]=a[i];

for(int i=1;i<=n;i++)
{
    for(int j=1;j<i;j++)
    {
       if(lik[j][i]&&dp[j]+a[i]>dp[i])
       {
        dp[i]=dp[j]+a[i];
        pre[i]=j;
       }
    }
   
}

int id=-1;
int Max=0;

for(int i=1;i<=n;i++)
{
    if(Max<dp[i])
    {
        id=i;
        Max=dp[i];
    }
}
int tmp=id;
vi ans;
while(pre[id])
{
    ans.push_back(pre[id]);
    id=pre[id];
}
for(int i=(int)ans.size()-1;i>=0;i--)cout<<ans[i]<<" ";//倒序输出
cout<<tmp<<" ";
cout<<endl;

cout<<Max<<endl;


    return 0;
}