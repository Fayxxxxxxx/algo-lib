//双端链表加反悔贪心 天才想法
// 我们每次循环都不是单纯在问：
// “下一条边选谁？”
// 而是在问：
// “如果我要让当前配对数量再增加 1，对我来说最便宜的办法是什么？”
//要么反悔 那么数量还是+1 如果不反悔那么数量还是+1
//也就是把反悔需要的代价也加进堆里面 如果其他值比代价还要大 那么
//当然是优先进行反悔
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
struct node
{
  ll dis;
  int id;
};

struct tmp
{
  bool operator()(node&a,node&b)
  {
      return a.dis>b.dis;
  }
};
const int N=100005;
const ll INF=(1LL<<60);

int l[N],r[N];
bool removed[N];
ll d[N];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n,k;
cin>>n>>k;
vector<ll> nums(n+1);
for(int i=1;i<=n;i++)cin>>nums[i];
priority_queue<node,vector<node>,tmp> pq;
for(int i=1;i<n;i++)
{
    d[i]=nums[i+1]-nums[i];
    l[i]=i-1;
    r[i]=i+1;
    pq.push({d[i],i});  
}
ll ans=0;
l[0]=0;//这样等到后面设removed的时候好设
r[0]=1;
l[n]=n-1;
r[n]=n;//这样等到后面设removed的时候好设
d[0]=INF;//哨兵保护
d[n]=INF;//哨兵保护
while(k--)
{
    while(removed[pq.top().id])
    {
        pq.pop();
    }
    
    int id=pq.top().id;
    pq.pop();
    int left=l[id];
    int right=r[id];
    
    ll dis=d[id];
    ans+=dis;//先选这条边 然后为未来反悔做准备

    d[id]=d[right]+d[left]-dis;
    if(left!=0)removed[left]=true;//删掉贪心的左右两边
    if(right!=n)removed[right]=true;//因为没有必要取了 
    l[id]=l[left];
    r[id]=r[right];
    r[l[id]]=id;
    l[r[id]]=id;
    pq.push({d[id],id});
}
cout<<ans<<endl;
    return 0;
}