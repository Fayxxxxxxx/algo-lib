#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
int r,c;
bool col_same(vector<vector<char>> &grid,int a,int b)
{
    for(int i=1;i<=r;i++)
    {
        if(grid[i][a]!=grid[i][b])
        {
            return false;
        }
    }
    return true;
}
bool row_same(vector<vector<char>> &grid,int a,int b)
{
    for(int i=1;i<=c;i++)
    {
        if(grid[a][i]!=grid[b][i])
        {
            return false;
        }
    }
    return true;
}
int step1(vector<vector<char>> &grid)
{
    vector<int> ne(c+1);
    //先用 c

    for(int i=2,j=0;i<=c;i++)
    {
        while(j&&!col_same(grid,i,j+1))
        {
           j=ne[j];
        }
        if(col_same(grid,i,j+1))
        {
            j++;
        }
        ne[i]=j;
    }

    return c-ne[c];
}
int step2(vector<vector<char>> &grid)
{
    vector<int> ne(r+1);
    //先用 c

    for(int i=2,j=0;i<=r;i++)
    {
        while(j&&!row_same(grid,i,j+1))
        {
           j=ne[j];
        }
        if(row_same(grid,i,j+1))
        {
            j++;
        }
        ne[i]=j;
    }

    return r-ne[r];
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>r>>c;
vector<vector<char>> grid(r+1,vector<char>(c+1));
for(int i=1;i<=r;i++)
{
    for(int j=1;j<=c;j++)
    {
        cin>>grid[i][j];
    }
}
int col=step1(grid);
int row=step2(grid);

cout<<col*row<<endl;



    return 0;
}