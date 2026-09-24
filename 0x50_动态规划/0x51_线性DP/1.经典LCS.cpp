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
