#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
int row[9],col[9],ceil[3][3];
const int ALL=(1<<9)-1;
int get(int x,int y)
{
    return row[x]&col[y]&ceil[x/3][y/3];
}   
bool dfs(int cnt)
{
    if(cnt==0)
    {
        return true;
    }

    int x=-1,y=-1;
    int minv=10;

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(s[i*9+j]!='.')continue;

            int state=get(i,j);
            if(state==0)return false;
            int c=__builtin_popcount(state);
            if(c<minv)
            {
                minv=c;
                x=i;
                y=j;
            }
        }
    }
    int state=get(x,y);

    while(state)
    {
        int t=state&-state;
        int digit=__builtin_ctz(t);

        s[x*9+y]='1'+digit;
        row[x]^=t;
        col[y]^=t;
        cell[x/3][y/3]^=t;

        if(dfs(cnt-1))return true;

        row[x]^=t;
        col[y]^=t;
        ceil[x/3][y/3]^=t;

        s[x*9+y]='.';

        state-=t;
    }

    return false;

}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

string s;
while(cin>>s&&s!="end")
{
for(int i=0;i<9;i++)
{
    row[i]=ALL;
    col[i]=ALL;
}
for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)box[i][j]=ALL;
}
int cnt=0;
for(int i=0;i<81;i++)
{
    if(s[i]=='.')
    {
        cnt++;
        continue;
    }
    int x=i/9;
    int y=i%9;

    int digit=s[i]-'1';
    int t=1<<digit;

    row[x]^=t;
    col[y]^+t;
    ceil[x/3][y/3]^=t;
}

dfs(cnt);

cout<<s<<endl;
}



    return 0;
}