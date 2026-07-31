#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

vector<vector<int>> arr(4,vector<int>(4,0));

void turn(int x,int y,vector<vector<int>>& arr){
    for(int i=0;i<4;i++)arr[x][i]^=1;
    for(int i=0;i<4;i++)arr[i][y]^=1;

    arr[x][y]^=1;
}

struct dex
{
    int x;
    int y;
};
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int ans=INT_MAX;
vector<dex> res;

for(int i=0;i<4;i++)
{
    for(int j=0;j<4;j++)
    {
        char x;
        cin>>x;

        if(x=='+')arr[i][j]=0;
        else arr[i][j]=1;
    }
}

for(int mask=0;mask<(1<<16);mask++)
{
    vector<vector<int>> tmp=arr;
    vector<dex> num;
    int cnt=0;

    for(int k=0;k<16;k++)
    {
        if((mask>>k)&1)
        {
            int x=k/4;
            int y=k%4;
            turn(x,y,tmp);
            cnt++;
            num.push_back({x+1,y+1});
        }
    }
    bool flag=true;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++){
        if(!tmp[i][j])flag=false;
        }
    }

    if(flag)
    {
        if(ans>cnt)
        {
            ans=cnt;
            res=num;
        }
    }
}

cout<<ans<<endl;
for(auto e:res)
{
    cout<<e.x<<" "<<e.y<<endl;
}

    return 0;
}