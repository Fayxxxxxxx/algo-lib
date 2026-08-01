#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
vector<vector<int>> prefix;
int n;
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n;
prefix.resize(n+1,vector<int>(n+1));
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=n;j++)
    {
        cin>>prefix[i][j];
    }
}
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=n;j++)
    {
        prefix[i][j]+=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
    }
}
int ans=INT_MIN;
for(int i=0;i<n*n;i++)
{
    for(int j=i;j<n*n;j++){
      int x1=i/n+1;
      int y1=i%n+1;

      int x2=j/n+1;
      int y2=j%n+1;
      if(y1<=y2)
      ans=max(ans,prefix[x2][y2]-prefix[x2][y1-1]-prefix[x1-1][y2]+prefix[x1-1][y1-1]);
    }
}
cout<<ans<<endl;



    return 0;
}




#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
vector<vector<int>> prefix;
int n;
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n;
prefix.resize(n+1,vector<int>(n+1));
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=n;j++)
    {
        cin>>prefix[i][j];
        prefix[i][j]+=prefix[i][j-1];
    }
}

int ans=INT_MIN;
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=n;j++){
      int last=0;
      for(int k=1;k<=n;k++)
      {
        last=max(last,0LL)+prefix[j][k]-prefix[i-1][k];
        ans=max(ans,last);
      }
    }
}
cout<<ans<<endl;



    return 0;
}




