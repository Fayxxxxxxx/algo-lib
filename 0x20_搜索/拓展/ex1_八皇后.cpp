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
int n;
vector<vi> grid(14,vi(14,0));
vector<vi> ans;
vi path;
const int N=50;
vb vis(N);
bool safe(int x,int y)
{
    for(int i=0;i<n;i++)
    {
        if(grid[x][i]||grid[i][y])return false;
    }

    if(vis[x-y+n]||vis[x+y+n])return false;
    return true;
}
void dfs(int u)
{
    if(u==n)
    {
      ans.push_back(path);
       return ;
    }

    for(int i=0;i<n;i++)
    {
      if(safe(u,i))
      {
        grid[u][i]=1;
        path.push_back(i+1);
        vis[u-i+n]=true;
        vis[u+i+n]=true;
        dfs(u+1);
        vis[u+i+n]=false;
        vis[u-i+n]=false;
        path.pop_back();
        grid[u][i]=0;
      }
    }
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n;
dfs(0);
for(int i=0;i<3;i++)
{
    for(int x:ans[i])cout<<x<<" ";
    cout<<endl;
}
cout<<ans.size()<<endl;

    return 0;
}