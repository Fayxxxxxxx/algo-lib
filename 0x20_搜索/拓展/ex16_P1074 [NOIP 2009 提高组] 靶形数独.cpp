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

int col[9],row[9],grid[3][3];
int ALL=(1<<9)-1;

string s;

int ans=-1;

int get_score(int x,int y)
{
    return 10-max(abs(x-4),abs(y-4));
}

int get_num(int x,int y)
{
    return row[x]&col[y]&grid[x/3][y/3];
}

void dfs(int cnt,int cur)
{
    if(cnt==0)
    {
        ans=max(ans,cur);
        return;
    }

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

        if(t==0)return;

        if(num<minv ||
          (num==minv && get_score(nx,ny)>get_score(x,y)))//只需要增加一个优先级就可以了
        {//因为其实这样的算法只是进行了优化 考虑了优先级
        //并没有去影响到最后求出来的最大值 只要不提前返回
        //而之前dfs设为bool 得到一个值后就直接返回了 所以
        //这里设为void 去计算即可
            x=nx;
            y=ny;
            minv=num;
        }
    }

    int state=get_num(x,y);

    for(int num=8;num>=0;num--)
    {
        int t=1<<num;

        if(!(state&t))continue;

        row[x]^=t;
        col[y]^=t;
        grid[x/3][y/3]^=t;

        s[x*9+y]='1'+num;

        dfs(cnt-1,cur+(num+1)*get_score(x,y));

        s[x*9+y]='0';

        row[x]^=t;
        col[y]^=t;
        grid[x/3][y/3]^=t;
    }
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
    int cur=0;

    for(int i=0;i<81;i++)
    {
        if(s[i]=='0')
        {
            cnt++;
            continue;
        }

        int x=i/9;
        int y=i%9;

        int num=s[i]-'1';
        int t=1<<num;

        if(!(row[x]&t) ||
           !(col[y]&t) ||
           !(grid[x/3][y/3]&t))//这里需要考虑输入有误的问题
        {
            cout<<-1<<endl;
            return 0;
        }

        row[x]^=t;
        col[y]^=t;
        grid[x/3][y/3]^=t;

        cur+=(num+1)*get_score(x,y);
    }

    dfs(cnt,cur);

    cout<<ans<<endl;

    return 0;
}