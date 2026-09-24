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
const int N=1e4+5;
vector<vi> nums(N);
int dp[N];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n,k;
    cin>>n>>k;

    for(int i=1;i<=k;i++)
    {
        int p,t;
        cin>>p>>t;

        nums[p].push_back(t);
    }

    for(int i=n;i>=1;i--)//逆向的dp 以i为开头的最大空闲时间 这样才好去递推
    //善于定义状态 才是真本事
    {
        if(nums[i].empty())
        {
            dp[i]=dp[i+1]+1;
        }
        else
        {
            for(int t:nums[i])
            {
                dp[i]=max(dp[i+t],dp[i]);
            }
        }
    }
    cout<<dp[1]<<endl;


    return 0;
}