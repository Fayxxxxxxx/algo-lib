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
int n,m,x,y;
vector<vi> grid;
int dir[8][2]={{-2,1},{-1,2},{2,1},{1,2},{2,-1},{1,-2},{-1,-2},{-2,-1}};
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n>>m>>x>>y;
grid.resize(n+1,vi(m+1,-1));
grid[x][y]=0;
queue<pii> q;
q.push({x,y});

    while(!q.empty()){
        auto [dx,dy]=q.front();
        q.pop();
        for(int i=0;i<8;i++)
        {
            int nx=dir[i][0]+dx;
            int ny=dir[i][1]+dy;

            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&grid[nx][ny]==-1)
            {
                grid[nx][ny]=grid[dx][dy]+1;
                q.push({nx,ny});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)cout<<grid[i][j]<<" ";
        cout<<endl;
    }


    return 0;
}