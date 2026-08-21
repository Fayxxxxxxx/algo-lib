#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n;
cin>>n;
priority_queue<int,vi,greater<int>> pq;
for(int i=0;i<n;i++)
{
    int x;
    cin>>x;
    pq.push(x);
}
ll ans=0;
while(pq.size()!=1)
{
    int c=0;
    c+=pq.top();
    pq.pop();
    c+=pq.top();
    pq.pop();
    ans+=c;
    pq.push(c);
}
cout<<ans<<endl;


    return 0;
}