#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int N=1e5+10;
int son[N][10];
int cnt[N];
int idx;
void insert(string s)
{
    int u=0;
    for(char x:s)
    {
        int y=x-'0';
        if(son[u][y]==0)
        {
            son[u][y]=++idx;
        }
        u=son[u][y];
    }
    cnt[u]++;
}
bool query(string s)
{
    int u=0;
    for(char x:s)
    {
        int  y=x-'0';
        if(son[u][y]==0)
        {
            return false;
        }
        u=son[u][y];
        if(cnt[u])
        {
            return true;
        }
    }
  return true;
}
void solve()
{
    memset(son,0,sizeof(son));
    memset(cnt,0,sizeof(cnt));
    idx=0;
    int n;
    cin>>n;
    bool flag=true;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s; 
        if(i>0)
        {
          if(query(s))   
          {
            flag=false;
          }
        }
        insert(s);
    }
    if(!flag)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
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