//只适用于二叉

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
vector<string> ans;
struct node
{
int l;
int r;
ll val;
};
struct cmp
{
bool operator()(node&a,node&b)
{
    return a.val<b.val;
}
};
vector<node> tr;
void dfs(int id,string s)
{
    if(tr[id].l==-1&&tr[id].r==-1)
    {
        ans[id]=s;
        return ;
    }

    int l=tr[id].l;
    int r=tr[id].r;

    dfs(l,s+'0');
    dfs(r,s+'1');
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n,k;
cin>>n>>k;
ans.resize(n);
priority_queue<pll,vector<pll>,greater<pll>> pq;
for(int i=0;i<n;i++)
{
    ll x;
    cin>>x;

    tr.push_back({-1,-1,x});

    int id=tr.size()-1;
    pq.push({x,id});
}
while(pq.size()>1)
{
    auto [w1,u]=pq.top();
    pq.pop();

    auto [w2,v]=pq.top();
    pq.pop();

    tr.push_back({u,v,w1+w2});
    int fa=tr.size()-1;
    pq.push({w1+w2,fa});
}
int root=pq.top().second;
dfs(root,"");
ll res=0;
ll Max=0;
for(string s:ans)
{
res+=(ll)s.size();
Max=max(Max,(ll)s.size());
cout<<s<<endl;
}

cout<<res<<endl;
cout<<Max<<endl;

    return 0;
}

//k叉

//需要增加假0 让k叉huffman树完整 比如我一次取三个
//树里共5个 则-3+1=2 这样是完美的
//如果树里原来就4个呢 那么就没法得到唯一的1个 所以要
//加一个0 让他个数变为5 这样就可以完美求解了
//并且这样不影响编码 因为0*val=0
//假设补完后有n个 每次要消耗k-1
//所以 n-t*(k-1)==1 则n-1=t*(k-1) 所以(n-1)%k-1==0
//这样不断加来得到
//这题都不用建树
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
int n,k;
cin>>n>>k;
//魔鬼细节 先按值从小到大排序 再按高度从小到大排序
//这样高度可以尽可能的低
priority_queue<pll,vector<pll>,greater<pll>> pq;
for(int i=0;i<n;i++)
{
    ll x;
    cin>>x;

    pq.push({x,0});
}
while((pq.size()-1)%(k-1)!=0)
{
    pq.push({0,0});
}
ll res=0;

while(pq.size()>1)
{
    ll sum=0;
    ll Max=0;

    for(int i=0;i<k;i++)
    {
        auto [w,h]=pq.top();
        pq.pop();

        Max=max(h,Max);
        sum+=w;
    }

    res+=sum;
    pq.push({sum,Max+1});
}
cout<<res<<endl;
cout<<pq.top().second<<endl;



    return 0;
}


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
int n,k;
cin>>n>>k;
priority_queue<pll,vector<pll>,greater<pll>> pq;
for(int i=0;i<n;i++)
{
    int x;
    cin>>x;
    pq.push({x,0});
}
while(((int)pq.size()-1)%(k-1)!=0)
{
    pq.push({0,0});
}
ll res=0;
while((int)pq.size()>1)
{
    ll Max=0;
    ll total=0;
    for(int i=0;i<k;i++)
    {
        auto [u,h]=pq.top();
        pq.pop();
        total+=u;
        Max=max(Max,h);
    }
    res+=total;
    pq.push({total,Max+1});
}
cout<<res<<endl;
cout<<pq.top().second+1<<endl;



    return 0;
}