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
    
    prefix[i]=prefix[i-1]+x;
}

deque<int> dq;
dq.push_back(0);
int ans=LLONG_MIN;
for(int i=1;i<=n;i++)
{
    while(!dq.empty()&&dq.front()<i-m)
    {
        dq.pop_front();
    }
    
    ans=max(ans,prefix[i]-prefix[dq.front()]);
    
    while(!dq.empty()&&prefix[i]<=prefix[dq.back()])
    {
        dq.pop_back();
    }
    dq.push_back(i);
}
cout<<ans<<endl;


    return 0;
}