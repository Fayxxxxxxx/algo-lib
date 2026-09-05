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
const int INF=0x3f3f3f3f;
//取决于最长的电话线长度 假设最长的电话线长度是x 则二分x 让>x的个数小于等于k 则
//这个方案合理 属于最大最小值
//很显然是有单调性的 如果当前的值大于x则相当于边权为1 如果当前的值小于等于x相当于边权为0
//由此将题目转化为0/1bfs型问题 妙哉
vector<vector<pii>> graph;
int n,p,k;
bool check(int x)
{
    vi dist(n+1,INT_MAX);
    deque<pii> dq;
    dist[1]=0;
    dq.push_back({1,0});

    while(!dq.empty())
    {
        auto [u,total]=dq.front();
        dq.pop_front();
        
        if(dist[u]!=total)continue;
        
        for(auto [v,w]:graph[u])
        {
            int cost=(w>x);
            if(dist[v]>dist[u]+cost)
            {
                dist[v]=dist[u]+cost;

                if(cost==0)
                {
                    dq.push_front({v,dist[v]});
                }
                else
                {
                    dq.push_back({v,dist[v]});
                }
            }
        }
    }

    return dist[n]<=k;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
    cin>>n>>p>>k;
    graph.resize(n+1);
    for(int i=0;i<p;i++)
    {
        int a,b,l;
        cin>>a>>b>>l;
        graph[a].push_back({b,l});
        graph[b].push_back({a,l});
    }
    int left=-1;
    int right=1e6+1;
    while(right-left>1)
    {
        int mid=left+(right-left)/2;

        check(mid)?right=mid:left=mid;
    }
    if(right!=1e6+1)
    {
        cout<<right<<endl;
    }
    else
    {
      cout<<-1<<endl;
    }


    return 0;
}