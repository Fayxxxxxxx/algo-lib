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
const int INF=0x3f3f3f3f;//矩阵乘法的快速幂很像一般的快速幂 因为矩阵相乘满足结合律
//但是不满足交换律 所以不能乱换顺序 并且要对mul进行重载 还有就是初始的res=1 这个1
//要换为矩阵意义上的1 也就是对于i*i的矩阵 其主对角线(左上到右下)上都是1 其余都是零
const ll mod=10000;
//对于斐波那契额这道题我们注意到
//我们需要求解Fn+1需要Fn和Fn-1
//所以也需要知道Fn的信息
//不妨令矩阵为[1,1]
//           [1,0]这样第一位就是Fn+Fn-1
//                    第二位就是Fn 
struct matrix
{
ll a[2][2];
};
matrix mul(matrix& A,matrix& B)
{
    matrix C={};

    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                C.a[i][j]=(C.a[i][j]%mod+(i128)A.a[i][k]*B.a[k][j]%mod)%mod;
            }
        }
    }
    return C;
}
matrix qpow(matrix& a,ll b)
{
    matrix res={};

    res.a[0][0]=1;
    res.a[1][1]=1;

    while(b)
    {
        if(b&1)res=mul(res,a);
        b>>=1;
        a=mul(a,a);
    }

    return res;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
ll n;
while(cin>>n&&n!=-1)
{
if(n==0)
{
    cout<<0<<endl;
    continue;
}

matrix T={{{1,1},{1,0}}};
matrix ans=qpow(T,n-1);

cout<<ans.a[0][0]<<endl;
}


    return 0;
}