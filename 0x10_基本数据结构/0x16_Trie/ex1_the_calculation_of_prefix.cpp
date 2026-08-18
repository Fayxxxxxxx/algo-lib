#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

const int N=1e6+10;
int son[N][26];
int pass[N];
int cnt[N];
int idx;
void insert(string s)
{
    int u=0;
    
    for(char t:s)
    {
      int x=t-'a';

      if(!son[u][x])
      {
        son[u][x]=++idx;
      }

      u=son[u][x];
      pass[u]++;
    }
    cnt[u]++;
}
int query(string s)
{
    int ans=0;
    
    int u=0;
    for(char t:s)
    {
        int x=t-'a';

        if(!son[u][x])
        {
            return ans;
        }
        u=son[u][x];
        ans+=cnt[u];
    }
    return ans;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n,m;
cin>>n>>m;
for(int i=0;i<n;i++)
{
    string s;
    cin>>s;
    insert(s);
}
for(int i=0;i<m;i++)
{
    string s;
    cin>>s;
    cout<<query(s)<<endl;
}

    return 0;
}