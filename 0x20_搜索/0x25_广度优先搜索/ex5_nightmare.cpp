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
vector<string> grid;
vector<pii> ghost;
int n,m;
int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
bool safe(int x,int y,int t)
{
    if(x<0||x>n-1||y<0||y>m-1||(grid[x][y]=='X'))
    {
        return false;
    }

    for(auto [gx,gy]:ghost)
    {
        int dis=abs(x-gx)+abs(y-gy);

        if(dis<=2*t)return false;
    }
    return true;
}
bool extend(queue<pii>& q,vector<vi>& self,
vector<vi>& other,int t)
{
    int sz=q.size();

    while(sz--)
    {
        auto [x,y]=q.front();
        q.pop();
        if(!safe(x,y,t))continue;
        if(other[x][y])return true;
        for(int i=0;i<4;i++)
        {
            int nx=x+dir[i][0];
            int ny=y+dir[i][1];

            if(!safe(nx,ny,t))continue;
            if(self[nx][ny])continue;
            if(other[nx][ny])return true;

            self[nx][ny]=1;
            q.push({nx,ny});
        }
    }
    return false;
}
int bfs(pii G,pii M)
{
    queue<pii> man;
    queue<pii> girl;

    vector<vi> vis_man(n,vi(m));
    vector<vi> vis_girl(n,vi(m));

    man.push(M);
    girl.push(G);

    vis_man[M.first][M.second]=1;
    vis_girl[G.first][G.second]=1;
    
    int t=0;
    while(!man.empty()&&!girl.empty())
    {
        t++;

        for(int i=0;i<3;i++)
        {
          if(extend(man,vis_man,vis_girl,t))return t;
        }

        if(extend(girl,vis_girl,vis_man,t))return t;
    }
    return -1;
}
void solve()
{
    cin>>n>>m;
    grid.resize(n);
    ghost.clear();

    pii G,M;
    for(int i=0;i<n;i++)
    {
        cin>>grid[i];
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='M')
            {
                M={i,j};
            }
            else if(grid[i][j]=='G')
            {
                G={i,j};
            }
            else if(grid[i][j]=='Z')
            {
                ghost.push_back({i,j});
            }
        }
    }

    int ans=bfs(G,M);

    cout<<ans<<endl;
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