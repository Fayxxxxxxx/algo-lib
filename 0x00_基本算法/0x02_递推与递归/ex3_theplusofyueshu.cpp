#include<bits/stdc++.h>
using namespace std;
int mod=9901;
typedef long long ll;


ll power(ll a,ll b)
{
    ll res=1;
    
    while(b)
    {
        if(b&1)
        {
            res=(res*a)%mod;
        }
        b>>=1;
        a=(a*a)%mod;
    }
    
    return res;
}

ll sum(int p,int n)
{
    if(n==0)
    {
        return 1;
    }
    if(n==1)
    {
        return (1+p)%mod;
    }
    if(n&1)
    {
        return ((ll)sum(p,n/2)%mod*(1+(ll)power(p,n/2+1)%mod))%mod;
    }
    else
    {
        return ((ll)sum(p,n/2-1)%mod*(1+(ll)power(p,n/2+1))%mod+(ll)power(p,n/2))%mod;//见书上的公式 进行递归拆分->分治的思想
    }
}

ll disolve(int n,int b)
{
    if(n==0)
    {
        return 0;
    }
    ll res=1;
    for(int i=2;i*i<=n;i++)
    {
        int cnt=0;
        
        while(n%i==0)
        {
            cnt++;
            n/=i;
        }
        
        res=(res*sum(i,cnt*b))%mod;
    }
    
    if(n>1)
    {
        res=(res*sum(n,b))%mod;
    }
    
    return res;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

int a,b;
cin>>a>>b;

cout<<disolve(a,b);

    return 0;
}