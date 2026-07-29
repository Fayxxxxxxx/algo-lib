#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int arr[4][4]={};

struct dex
{
    int x;
    int y;
};
void turn(int x,int y)
{
   for(int i=0;i<4;i++)arr[x][i]^=1;
   for(int i=0;i<4;i++)arr[i][y]^=1;
   arr[x][y]^=1;
}
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

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

int ans=INT_MAX;
vector<dex> res;

for(int mask=0;mask<(1<<16);mask++)
{
    int cnt=0;
    vector<dex> tmp;

   for(int j=0;j<16;j++)
   {
    if((mask>>j)&1){
        int x=j/4;
        int y=j%4;

        turn(x,y);
        cnt++;
        tmp.push_back({x+1,y+1});
    }
   }
   bool flag=true;
   for(int i=0;i<4;i++)
   {
    for(int j=0;j<4;j++)
    {
        if(!arr[i][j])flag=false;
    }
   }

   if(flag)
   {
    if(ans>cnt)
    {
        ans=cnt;
        res=tmp;
    }
   }
}


cout<<ans<<endl;

for(int i=0;i<ans;i++)
{
    cout<<res[i].x<<" "<<res[i].y<<endl;
}
    return 0;
}

