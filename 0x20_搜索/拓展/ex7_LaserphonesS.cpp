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
int m,n;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
struct node
{
int x,y,dir;
};
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>m>>n;
vector<pii> cows;
vector<vc> grid(n,vc(m));
vector<vector<vi>>dist(n,vector<vi>(m,vi(4,INT_MAX)));
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        cin>>grid[i][j];
        if(grid[i][j]=='C')
        {
            cows.push_back({i,j});
        }
    }
}
int sx=cows[0].first;
int sy=cows[0].second;
int ex=cows[1].first;
int ey=cows[1].second;
dist[sx][sy][0]=0;
dist[sx][sy][1]=0;
dist[sx][sy][2]=0;
dist[sx][sy][3]=0;
deque<node> q;
q.push_back({sx,sy,0});
q.push_back({sx,sy,1});
q.push_back({sx,sy,2});
q.push_back({sx,sy,3});
int ans=INT_MAX;
while(!q.empty())
{
    auto [gx,gy,to]=q.front();
    q.pop_front();
    
    if(gx==ex&&gy==ey)ans=min(ans,dist[gx][gy][to]);

    for(int i=0;i<4;i++)
    {
        if((to+2)%4==i)continue;//这个方向我不走
        int nx=gx+dx[i];
        int ny=gy+dy[i];
        int ndir=i;
       
        if(nx<0||nx>=n||ny<0||ny>=m||grid[nx][ny]=='*')continue;

        int w=(to!=ndir);

        if(dist[nx][ny][ndir]>dist[gx][gy][to]+w)
        {
            dist[nx][ny][ndir]=w+dist[gx][gy][to];

            if(w==0)
            {
                q.push_front({nx,ny,ndir});
            }
            else
            {
                q.push_back({nx,ny,ndir});
            }
        }
 
    }
}
cout<<ans<<endl;
    return 0;
}