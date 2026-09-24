//设f[i] 为以i为结尾的子段和的方案
//属性是取最大/最小

//为什么设置为以i为结尾的字段和而不是前i个数字的最大字段和呢
//因为如果是后者那将不太具有连续性 没有传递性
//而如果是设置以i为结尾的字段和
//那么此时考虑最后一位
//目前的Max=max(Max,f[i-1]+a[i])
//等于以i-1为结尾的字段和+自己本身
//f[i]=max(f[i-1]+a[i],a[i]);

//首先f[i]都可以初始化为自己本身
//所以代码里面的a[i]实际上就是f[i]自己本身


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
using vs=vector<string>;
using i128=__int128_t;
const int INF=0x3f3f3f3f;
const int N=2e5+5;
int f[N];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
    int n;
    cin>>n;
for(int i=1;i<=n;i++)
{
    cin>>f[i];
}


    for(int i=1;i<=n;i++)
    {
        f[i]=max(f[i],f[i-1]+f[i]);//新的以i为结尾的最大
        //子序和=以i-1为结尾的最大自序和加上自己的值 或者就是自己本身
        
    }
int Max=INT_MIN;

    for(int i=1;i<=n;i++)
    {
        Max=max(Max,f[i]);
    }
    cout<<Max<<endl;

    return 0;
}