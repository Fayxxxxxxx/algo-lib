#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int N=300005;
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n,m;
cin>>n>>m;

vector<int> prefix(N);

for(int i=1;i<=n;i++)
{
    int x;
    cin>>x;
    
    prefix[i]=prefix[i-1]+x;//因为求一个区间 所以求前缀和
}

deque<int> dq;
dq.push_back(0);//把下标0加入进去 这样保持统一性
int ans=LLONG_MIN;
for(int i=1;i<=n;i++)
{
    while(!dq.empty()&&dq.front()<i-m)//过期了
    {
        dq.pop_front();//这里为什么是i-m而不是i-m+1呢 因为是前缀和的下标 left=r-1 所以dq.front()最后其实是等于left+1 所以左右消去1
    }
    
    ans=max(ans,prefix[i]-prefix[dq.front()]);
    
    while(!dq.empty()&&prefix[i]<=prefix[dq.back()])//我新加进来的 数字又大 又新 更容易满足长度小于等于m 所以当然要把后面的这些不满足的给他踢掉
    {
        dq.pop_back();
    }
    dq.push_back(i);
}
cout<<ans<<endl;


    return 0;
}