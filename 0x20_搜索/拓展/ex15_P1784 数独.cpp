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
int col[9],row[9],grid[3][3];//每一行 每一列 每一个块 具体是那个被占了 可用
int ALL=(1<<9)-1;

string s;
int get_num(int x,int y)
{
    return row[x]&col[y]&grid[x/3][y/3];
}
bool dfs(int cnt)
{
    if(cnt==0)return true;
    int minv=10;
    int x=-1;
    int y=-1;

    for(int i=0;i<81;i++)
    {
        if(s[i]!='0')continue;

        int nx=i/9;
        int ny=i%9;

        int t=get_num(nx,ny);
        int num=__builtin_popcount(t);
        if(t==0)return false;
       
        if(num<minv)
        {
            x=nx;
            y=ny;
            minv=num;
        }
    }

    int state=get_num(x,y);

    while(state)
    {
        int t=state&-state;
        int num=__builtin_ctz(t);
        row[x]^=t;
        col[y]^=t;
        grid[x/3][y/3]^=t;
        s[x*9+y]='1'+num;
        if(dfs(cnt-1))return true;
        s[x*9+y]='0';
        row[x]^=t;
        col[y]^=t;
        grid[x/3][y/3]^=t;
        state-=t;
    }
    return false;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
for(int i=0;i<81;i++)
{
    char x;
    cin>>x;
    s+=x;
}

    for(int i=0;i<9;i++)
    {
        col[i]=ALL;
        row[i]=ALL;
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            grid[i][j]=ALL;
        }
    }
    int cnt=0;
    for(int i=0;i<81;i++)
    {
        if(s[i]=='0')
        {
            cnt++;
            continue;
        }

        int x=i/9;
        int y=i%9;
        int t=s[i]-'1';
        row[x]^=(1<<t);
        col[y]^=(1<<t);
        grid[x/3][y/3]^=(1<<t);
    }
    dfs(cnt);
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<s[i*9+j]<<" ";
        }
        cout<<endl;
    }
    



    return 0;
}