//1.经典背包问题
//设f[i][j]是前i个物品中考虑,其体积<=j的合法方案
//属性是取最大

//考虑最后一个选与不选 
//1.不选f[i-1][j] 
//2.选f[i-1][j-v[i]]+w[i];

//所以有f[i][j]=max(f[i-1][j],f[i-1][j-v[i]]+w[i]);

//那么就是上一层的信息 所以如果压缩了之后我都需要上一层的信息
//则必须从右向左 不干扰小的


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
const int N=5e3;
int f[N];
int v[N];
int w[N];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n;
cin>>n;

for(int i=1;i<=n;i++)
{
    cin>>w[i]>>v[i];
}

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



//2.经典完全背包问题

//同样的内容
//属性也是

//但是对其j的讨论变了
//f[i][j]=max(f[i-1][j],f[i-1][j-v[i]]+w[i],f[i-1][j-2*v[i]]+2*w[i])...
//而f[i][j-v[i]]=max(f[i-1][j-v[i]],f[i-1][j-2*v[i]]+w[i]).....
//所以f[i][j]=max(f[i-1][j],f[i][j-v[i]]+w);
//因为转移依赖同一层容量更小的状态，所以容量必须从小到大枚举。


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
const int N=5e3;
int f[N];
int v[N],w[N];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n;
cin>>n;

for(int i=1;i<=n;i++)
{
    cin>>v[i]>>w[i];
}

for(int i=1;i<=n;i++)
{
    for(int j=v[i];j<=m;j++)
    {
        f[j]=max(f[j],f[j-v[i]]+w[i]);
    }
}
cout<<f[m]<<endl;


    return 0;
}


//3.经典区间DP 石子合并类题目   
//主要是对dp的定义:设f[i][j]表示[i,j]这个区间合并的合法方案
//属性是min

//则考虑左右的问题 假设k是左区间的右边界

//则k>=i k<j  
//f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+prefix[j]-prefix[i-1]);

//所以要先预处理prefix


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
const int N=3e2;
int f[N][N];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n;
cin>>n;

vi nums(n);
for(int i=1;i<=n;i++)cin>>nums[i];

vi prefix(n+1);

for(int i=1;i<=n;i++)prefix[i]=prefix[i-1]+nums[i];

//首先把所有的f[i][j]设置为0x3f
memset(f,0x3f,sizeof f);

for(int i=1;i<=n;i++)f[i][i]=0;

for(int len=2;len<=n;len++)
{
    for(int i=1;i+len-1<=n;i++)//左边的端点
    {
      int j=i+len-1;//右端点

      for(int k=i;k<j;k++)
      {
        f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+prefix[j]-prefix[i-1]);
      }
    }
}
cout<<f[1][n]<<endl;


    return 0;
}

//4.经典LCS问题
//设f[i][j]表示 字符串s的前i个字符 字符串t的前j个字符中考虑的合法方案
//属性是求最大
//对于此问题我需要考虑四种情况 
//1.选i 选j
//2.选i 不选j
//3.不选i 选j
//4.不选i 不选j
//对于1 那么就是f[i-1][j-1]+1
//对与2 那么就是f[i][j-1]
//对于3 那么就是f[i-1][j]
//对于4 那么就是f[i-1][j-1]

//f[i][j-1]和f[i-1][j]一定>=f[i-1][j-1]  所以实际上并不需要去考虑4


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
const int N=1e3;
int f[N][N];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
string s1;
string s2;

int n,m;
cin>>n>>m;

cin>>s1>>s2;
s1=" "+s1;
s2=" "+s2;
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++)
    {
        f[i][j]=max(f[i-1][j],f[i][j-1]);

        if(s1[i]==s2[j])
        {
            f[i][j]=max(f[i-1][j-1]+1,f[i][j]);
        }
    }
}
cout<<f[n][m]<<endl;

    return 0;
}
