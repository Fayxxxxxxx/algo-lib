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
int dir[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
int n,m;
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
while(cin>>n>>m&&n&&m)
{
    vector<vc> grid(n,vc(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)cin>>grid[i][j];
    }
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    vector<vi> dist(n,vi(m,INT_MAX));
    dist[x1][y1]=0;
    deque<pii> dq;
    dq.push_back({x1,y1});
    while(!dq.empty()){
        auto [x,y]=dq.front();
        dq.pop_front();

        if(x==x2&&y==y2)
        {
            cout<<dist[x2][y2]<<endl;
            break;
        }
        for(int i=0;i<4;i++)
        {
            int nx=x+dir[i][0];
            int ny=y+dir[i][1];

            if(!(nx>=0&&nx<n&&ny>=0&&ny<m))continue;
            
            int w=(grid[x][y]!=grid[nx][ny]);
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
}



    return 0;
}