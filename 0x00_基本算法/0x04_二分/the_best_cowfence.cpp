// 农夫约翰的农场由 N
//  块田地组成，每块地里都有一定数量的牛，其数量不会少于 1
//  头，也不会超过 2000
//  头。

// 约翰希望用围栏将一部分连续的田地围起来，并使得围起来的区域内每块地包含的牛的数量的平均值达到最大。

// 围起区域内至少需要包含 F
//  块地，其中 F
//  会在输入中给出。

// 在给定条件下，计算围起区域内每块地包含的牛的数量的平均值可能的最大值是多少。

// 输入格式
// 第一行输入整数 N
//  和 F
// ，数据间用空格隔开。

// 接下来 N
//  行，每行输入一个整数，第 i+1
//  行输入的整数代表第 i
//  片区域内包含的牛的数目。

// 输出格式
// 输出一个整数，表示平均值的最大值乘以 1000
//  再 向下取整 之后得到的结果。

// 数据范围
// 1≤N≤100000

// 1≤F≤N

// 输入样例：


#include<bits/stdc++.h>
using namespace std;
int n,f;
const int N=100010;
double sum[N];
int cows[N];

bool check(double mid)
{
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+cows[i]-mid;
    }
    
    double Min=0;
    
    for(int i=0,j=f;j<=n;j++,i++)
    {
        Min=min(Min,sum[i]);
        
        if(sum[j]>=Min)
        {
            return true;
        }
    }
    return false;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);


cin>>n>>f;

for(int i=1;i<=n;i++)
{
    cin>>cows[i];
}

double left=0;
double right=2000;

while(right-left>1e-5)
{
    double mid=left+(right-left)/2;
    
    check(mid)?left=mid:right=mid;
}

cout<<(int)(right*1000);//注意这里其实按照答案来说应该是left*1000 但是他是向下取整
//所以要用right 不然求出来会差1


    return 0;
}