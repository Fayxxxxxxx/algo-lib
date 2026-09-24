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
const int N=1e2+5;
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n;
cin>>n;
vi nums(n+1);
    for(int i=1;i<=n;i++)cin>>nums[i];

    vi pre(N,1);
    vi last(N,1);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(nums[i]>nums[j])
            pre[i]=max(pre[i],pre[j]+1);
        }
    }
    
    for(int i=n;i>=1;i--)
    {
        for(int j=n;j>i;j--)
        {
            if(nums[i]>nums[j])
            last[i]=max(last[i],last[j]+1);
        }
    }

    int ans=INT_MAX;

    for(int i=1;i<=n;i++)
    {
        ans=min(ans,n-(last[i]+pre[i]-1));
    }
    cout<<ans<<endl;
    

    
     


    return 0;
}