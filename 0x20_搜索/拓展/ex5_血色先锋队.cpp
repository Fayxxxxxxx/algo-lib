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
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int n,m,a,b;
vector<vi> nums;
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n>>m>>a>>b;
nums.resize(n+1,vi(m+1,-1));
vector<pii> domain;
queue<pii> q;
for(int i=0;i<a;i++)
{
    int x,y;
    cin>>x>>y;
    q.push({x,y});
    nums[x][y]=0;
}
    for(int i=0;i<b;i++)
    {
        int x,y;
        cin>>x>>y;
        domain.push_back({x,y});
    }
while(!q.empty())
{
    auto [dx,dy]=q.front();
    q.pop();
    for(int i=0;i<4;i++)
    {
        int nx=dx+dir[i][0];
        int ny=dy+dir[i][1];

        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&nums[nx][ny]==-1)
        {
            nums[nx][ny]=nums[dx][dy]+1;
            q.push({nx,ny});
        }
    }
}
for(auto [dx,dy]:domain)
{
    cout<<nums[dx][dy]<<endl;
}


    return 0;
}