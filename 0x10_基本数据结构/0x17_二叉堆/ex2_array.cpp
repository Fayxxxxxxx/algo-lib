#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
int n,m;
struct node
{
 int sum;
 int i;//a的索引
 int j;//b的索引
};
struct tmp
{
bool operator()(node& a,node& b)
{
    return a.sum>b.sum;
}
};
vi merge_v(vi &a,vi& b)
{
    priority_queue<node,vector<node>,tmp> pq;
    for(int i=0;i<n;i++)
    {
        pq.push({a[i]+b[0],i,0});
    }
    vi c;
    for(int k=0;k<n;k++)
    {
      auto e=pq.top();
      pq.pop();
      c.push_back(e.sum);

      if(e.j+1<n)
      {
        pq.push({a[e.i]+b[e.j+1],e.i,e.j+1});//为什么是j+1呢
        //因为第一排中最小的被我们取到 则最小的那个上面下面都比最小要小
        //而比最小大的那些数的右边一定比最小还要大
        //所以只有最小的右边有可能比当前比小根堆里面那些比最小的大的值
        //要来的小 所以取j+1作为下一个 反正是不是就看sum了
      }
    }
    return c;
}
void solve()
{
    cin>>m>>n;
    vector<vi> nums(m,vi(n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)cin>>nums[i][j];
    }
    for(auto &e:nums)
    {
        sort(e.begin(),e.end());
    }
    auto e=nums[0];
    for(int i=1;i<m;i++)
    {
        e=merge_v(e,nums[i]);
    }

    for(int x:e)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;
while(t--)
{
    solve();
}
    return 0;
}