#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int mod=1e9+7;

ll mul(ll a,ll b,int mod)
{
ll res=0;

while(b)
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