#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mod=1e9+7;


ll power(ll a,ll b,ll mod)
{
 ll res=1;
 a%=mod;

 while(b)
 {
    if(b&1)
    {
        res=res*a%mod;
    }
    b>>=1;
    a=(a*a)%mod;
 }
 return res%mod;
}
int main()
{
   cout<<power(2,3,mod);

    return 0;
}