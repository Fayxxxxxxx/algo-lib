f[i][j]//表示从 i到 i+2的j次 -1 共2的j次长

void ST_prewor()
{
    for(int i=1;i<=n;i++)f[i][0]=a[i];
    int t=log(n)/log(2)+1;
    for(int j=1;j<t;j++)
    {
        for(int i=1;i<=n-(1<<j)+1;i++)
        {
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
}

int ST_query(int l,int r)
{
    int k=log(r-l+1)/log(2);//这里k没有+1
    return max(f[l][k],f[r-(1<<k)+1][k]);
}



题目描述
给定一个长度为 N 的数列，和 M 次询问，求出每一次询问的区间内数字的最大值。

输入格式
第一行包含两个整数 N,M，分别表示数列的长度和询问的个数。

第二行包含 N 个整数（记为 a 
i
​
 ），依次表示数列的第 i 项。

接下来 M 行，每行包含两个整数 l 
i
​
 ,r 
i
​
 ，表示查询的区间为 [l 
i
​
 ,r 
i
​
 ]。

输出格式
输出包含 M 行，每行一个整数，依次表示每一次询问的结果。
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
int n,m;
vector<int> nums;
vector<vector<int>> f;
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

cin>>n>>m;
nums.resize(n+1);

    for(int i=1;i<=n;i++)cin>>nums[i];
    int t=log(n)/log(2)+1;

    f.resize(n+5,vector<int>(t+1));
    for(int i=1;i<=n;i++)f[i][0]=nums[i];

    for(int j=1;j<t;j++)
    {
        for(int i=1;i<=n-(1<<j)+1;i++)
        {
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }

    while(m--)
    {
        int l,r;
        cin>>l>>r;

        int k=log(r-l+1)/log(2);//没有+1 所以就是一半差不多

        cout<< max(f[l][k],f[r-(1<<k)+1][k])<<endl;
    }


    return 0;
}


