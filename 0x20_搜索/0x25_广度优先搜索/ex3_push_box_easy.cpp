#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
int dir[4][2]={{-1,1},{1,1},{1,-1},{-1,-1}};//右上 右下 左下 左上
const int N=505;
int dist[N][N];
const int INF=0x3f3f3f3f;
void solve()
{
    deque<pii> dq;
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)cin>>grid[i][j];
    }
    memset(dist,0x3f,sizeof(dist));//因为要比较大小 往小的看 所以dist初始化为INT_MAX
    dist[0][0]=0;
    dq.push_front({0,0});

    while(!dq.empty())
    {
        auto t=dq.front();
        dq.pop_front();

        int x=t.first;
        int y=t.second;

        for(int i=0;i<4;i++)
        {
            int nx=x+dir[i][0];
            int ny=y+dir[i][1];

            if(nx<0||nx>n||ny<0||ny>m)continue;

            int gx=min(x,nx);
            int gy=min(y,ny);

            char need=(dir[i][0]==dir[i][1]?'\\':'/');
            int w=(grid[gx][gy]!=need);


            if(dist[nx][ny]>dist[x][y]+w)
            {
                dist[nx][ny]=dist[x][y]+w;

                if(w==0)
                {
                    dq.push_front({nx,ny});
                }
                else
                {
                    dq.push_back({nx,ny});
                }
            }
        }
    }
     if(dist[n][m]!=INF)
        cout<<"NO SOLUTION"<<endl;
    else
        cout<<dist[n][m]<<endl;
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
int n,m;
const int N=505;
int dist[N][N];
int dir[4][2]={{-1,-1},{-1,1},{1,-1},{1,1}};
void solve()
{
    cin>>n>>m;
    memset(dist,0x3f,sizeof(dist));
    vector<vc> grid(n,vc(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)cin>>grid[i][j];
    }
    deque<pii> dq;
    dq.push_back({0,0});
    dist[0][0]=0;
    while(!dq.empty())
    {
        auto e=dq.front();
        dq.pop_front();
        int dx=e.first;
        int dy=e.second;
        
        for(int i=0;i<4;i++)
        {
            int nx=dx+dir[i][0];
            int ny=dy+dir[i][1];
            if(nx<0||nx>n||ny<0||ny>m)continue;
            int gx=min(nx,dx);
            int gy=min(ny,dy);
            char need=(dir[i][0]==dir[i][1]?'\\':'/');
            int w=(need!=grid[gx][gy]);

            if(dist[dx][dy]+w<dist[nx][ny])
            {
                dist[nx][ny]=dist[dx][dy]+w;

                if(w==0)
                {
                    dq.push_front({nx,ny});
                }
                else
                {
                    dq.push_back({nx,ny});
                }
            }
        }
    }
    int ans=dist[n][m];

    if(ans==INF)
    {
        cout<<ans<<endl;
    }else
    {
        cout<<"NO SOLUTION"<<endl;
    }

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