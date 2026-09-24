//我定义f[i][v]
//为只考虑前i个物品 其体积<=v的方案
//属性是取Max

//那么对于某一个物品而言 我都有选与不选的问题
//如果不选那么 问题就是考虑前i-1个物品 其体积<=v的方案
//如果是选那么 问题激素考虑前-1个物品 其体积<=v-V[i]的方案

//那么我此时的值就是取这两个方案的最大值
//第一个方案的值就是f[i-1][v];

//第二个方案的值是f[i-1][v-V[i]]+w[i]

//并且第二个方案必须满足v-V[i]>=0也就是要特判一手

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
const int N=1010;
int v[N],w[N];
int f[N][N];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n,m;
cin>>n>>m;
for(int i=1;i<=n;i++)cin>>v[i]>>w[i];

for(int i=1;i<=n;i++)
{
    for(int j=0;j<=m;j++)
    {
        f[i][j]=f[i-1][j];
        
        if(j>=v[i])
        {
            f[i][j]=max(f[i][j],f[i-1][j-v[i]]+w[i]);
        }
    }
}
cout<<f[n][m]<<endl;



    return 0;
}






//一维写法

//我不妨先把i都去掉然后去检验式子 
//我发现f[i][j]=max(f[i][j],f[i-1][j-v[i]]+w[i]);

//这一行如果去掉i 那么f[i-1][j-v[i]]就变为f[j-v[i]]
//那么对于这样而言 j-v[i]必然小于j 也就是我用小的值来搞大的
//值 关键就是此时这个j-v[i]是上一层的值还是这一层的值
//很显然是这一层的值 因为在去搞这个j之前 已经把j-v[i]搞好了
//他已经变为这一层的值了 而原式里面是f[i-1][j-v[i]]
//是i-1也就是上一层的值 矛盾 所以我们选择从大到小遍历
//也就是从m开始到v[i] 这样让大的值由小的值确定且更新大的值
//所以这样不会干扰到原来的数据 做到了一维化
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
const int N=1010;
int v[N],w[N];
int f[N];//如果是f[i][k] 那么一般第二行开始都是限制条件等等等等 第一个是遍历的层数和
//连续性条件
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n,m;
cin>>n>>m;
for(int i=1;i<=n;i++)cin>>v[i]>>w[i];

for(int i=1;i<=n;i++)
{
    for(int j=m;j>=v[i];j--)
    {
        f[j]=max(f[j],f[j-v[i]]+w[i]);
    }
}
cout<<f[m]<<endl;



    return 0;
}