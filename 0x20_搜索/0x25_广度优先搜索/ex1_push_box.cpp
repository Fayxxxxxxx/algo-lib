#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
char grid[505][505];
int n,m;
struct node
{
int x,y;//只记录最左/最上的
int lie;//0是立着 1是横躺 2是竖躺
};
int dir_x[3][4]={
{-2,1,0,0},
{-1,1,0,0},
{-1,2,0,0}
};//顺序是上下左右
int dir_y[3][4]={
    {0,0,-2,1},
    {0,0,-1,2},
    {0,0,-1,1}
};
int dir_l[3][4]={
    {2,2,1,1},
    {1,1,0,0},
    {0,0,2,2}
};
int dist[505][505][3]={};
bool inside(node& tmp)
{
  int x=tmp.x;
  int y=tmp.y;
  int lie=tmp.lie;

  if(lie==0)
  {
    return (x>=0&&x<n&&y>=0&&y<m);
  }
  else if(lie==1)
  {
    return (x>=0&&x<n&&y>=0&&y<m-1);
  }
  else
  {
    return (x>=0&&x<n-1&&y>=0&&y<m);
  }
}
bool valid(node tmp)
{
    int x=tmp.x;
    int y=tmp.y;
    int lie=tmp.lie;
    if(!inside(tmp))return false;

    if(lie==0)
    {
        if(grid[x][y]=='#'||grid[x][y]=='E')return false;
    }
    else if(lie==1)
    {
        if(grid[x][y]=='#'||grid[x][y+1]=='#')return false;
    }
    else
    {
        if(grid[x][y]=='#'||grid[x+1][y]=='#')return false;
    }

    return true;
}


int bfs(int tx,int ty,node init)
{
    queue<node> q;
    q.push(init);
    int x=init.x;
    int y=init.y;
    int lie=init.lie;
    
    dist[x][y][lie]=0;
    while(q.size())
    {
        auto e=q.front();
        q.pop();

        int nx=e.x;
        int ny=e.y;
        int nlie=e.lie;

        if(tx==nx&&ny==ty&&nlie==0)
        {
            return dist[tx][ty][0];
        }

        for(int i=0;i<4;i++)
        {
            int dx=nx+dir_x[nlie][i];
            int dy=ny+dir_y[nlie][i];
            int dlie=dir_l[nlie][i];

            if(!valid({dx,dy,dlie}))continue;
            if(dist[dx][dy][dlie]!=-1)continue;

            dist[dx][dy][dlie]=dist[nx][ny][nlie]+1;
            q.push({dx,dy,dlie});
        }
    }
    return -1;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
while(cin>>n>>m&&n&&m)
{
    memset(dist,-1,sizeof(dist));
    vector<pii> pos;
    int tx;
    int ty;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];

            if(grid[i][j]=='X')
            {
                pos.push_back({i,j});
            }
            else if(grid[i][j]=='O')
            {
                tx=i;
                ty=j;
            }
        }
    }
    int x,y,lie;
    if(pos.size()==1)
    {
       x=pos[0].first;
       y=pos[0].second;
       lie=0;
    }
    else 
    {
        int x1=pos[0].first;
        int x2=pos[1].first;
        int y1=pos[0].second;
        int y2=pos[1].second;
        if(x1==x2)
        {
            x=x1;
            y=min(y1,y2);
            lie=1;
        }
        else
        {
            x=min(x1,x2);
            y=y1;
            lie=2;
        }
    }

    int ans=bfs(tx,ty,{x,y,lie});

    if(ans==-1)cout<<"Impossible"<<endl;
    else
    {
        cout<<ans<<endl;
    }
}



    return 0;
}