#include<bits/stdc++.h>
using namespace std;
using ll =long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n,m;
cin>>n>>m;

vector<vi> g(n+1);
vi ind(n+1);

for(int i=0;i<m;i++)
{
    int a,b;
    cin>>a>>b;

    g[a].push_back(b);
    ind[b]++;
}

queue<int> q;
for(int i=1;i<=n;i++)
{
    if(!ind[i])q.push(i);
}
vi ans;

while(q.size())
{
    int x=q.top();
    q.pop();

    ans.push_back(x);

    for(int u:g[x])
    {
        ind[u]--;

        if(!ind[u])
        {
            q.push(u);
        }
    }
}

if(ans.size()!=n)
{
    cout<<"有环"<<endl;
}
else
{
    cout<<"无环"<<endl;
}



    return 0;
}


//下面是dfs写法 用color[2]来判断 0是未访问过 1是现在访问 2是之前已经访问过了

int color[N];
bool dfs(int x)
{
    color[x]=1;

    for(int u:g[x])
    {
        if(color[u]==2)
        {
            return false;
        }

        if(color[u]==0)
        {
            if(!dfs(u))
            {
                return false;
            }
        }
    }
    color[x]=2; 
    return true;
}

//然后这样是从条件最多的那个人开始的 所以如果想从尾巴开始需要reverse一下 