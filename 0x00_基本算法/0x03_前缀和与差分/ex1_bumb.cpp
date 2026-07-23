//以后前缀和就用1-base了 焊死了 麻烦死了我去



#include<bits/stdc++.h>
using namespace std;

int Max=5006;
int cal(vector<vector<int>> & prefix,int x1,int y1,int x2,int y2)
{
    return prefix[x2][y2]-prefix[x1-1][y2]-prefix[x2][y1-1]+prefix[x1-1][y1-1];
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

vector<vector<int>> prefix(Max,vector<int>(Max,0));

int n,r;
cin>>n>>r;

int Max_x=0,Max_y=0;

for(int i=0;i<n;i++)
{
    int x,y,w;
    cin>>x>>y>>w;

    Max_x=max(Max_x,x);
    Max_y=max(Max_y,y);

    prefix[x+1][y+1]+=w;
}

for(int i=1;i<=5005;i++)
{
    for(int j=1;j<=5005;j++)
    {
        prefix[i][j]+=prefix[i][j-1]+prefix[i-1][j]-prefix[i-1][j-1];
    }
}
if(Max_x+1<=r&&Max_y+1<=r)
{
    cout<<prefix[5005][5005]<<endl;
    return 0;
}
int ans=0;
for(int i=1;i+r-1<=5005;i++)
{
    for(int j=1;j+r-1<=5005;j++)
    {
       ans=max(ans,cal(prefix,i,j,i+r-1,j+r-1));
    }
}

cout<<ans<<endl;

    return 0;
}