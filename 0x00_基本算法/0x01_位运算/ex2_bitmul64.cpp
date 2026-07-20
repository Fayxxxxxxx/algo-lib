#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int mod=1e9+7;

ll mul(ll a,ll b,int mod)
{
ll res=0;

while(b)//重点是对这里第一位的理解 后面就是对第一位进行累乘就行了
//a*b 把b看为2进制 然后a*b 就是a对每一位2进制相乘相加
{
    if(b&1)
    {
        res=(res+a)%mod;
    }
    a=(a*2)%mod;
    b>>=1;
}
return res;
}
int main()
{
int a,b;
cin>>a>>b;

cout<<"a*b%p="<<" "<<mul(a,b,mod);

    return 0;
}