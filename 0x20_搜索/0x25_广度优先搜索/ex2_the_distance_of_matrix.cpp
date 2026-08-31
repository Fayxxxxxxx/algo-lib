#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
const int N=1005;
int dist[N][N];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
memset(dist,-1,sizeof(dist));
int n,m;
queue<pii> q;
vector<vi> grid(n,vi(m));
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        cin>>grid[i][j];
        dist[i][j]=0;
        if(grid[i][j]==1)
        {
            q.push({i,j});
        }
    }
}

while(q.size())
{
    auto e=q.front();
    q.pop();

    int nx=e.first;
    int ny=e.second;

    for(int i=0;i<8;i++)
    {
        int dx=nx+dir[i][0];
        int dy=ny+dir[i][1];

        if(dx>=0&&dx<n&&dy>=0&&dy<m)
        {
            if(dist[dx][dy]!=-1)continue;

            dist[dx][dy]=dist[nx][ny]+1;
            q.push({dx,dy});
        }
    }
}

for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        cout<<dist[i][j]<<" ";
    }
    cout<<endl;
}




    return 0;
}