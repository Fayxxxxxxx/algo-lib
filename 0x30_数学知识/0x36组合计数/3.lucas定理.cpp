ll qpow(ll a,ll b,ll mod)
{
    ll res=1;

    while(b)
    {
        if(b&1)res=(i128)res*a%mod;
        b>>=1;
        a=(i128)a*a%mod;
    }
    return res;
}
ll C(ll n,ll m,ll p)
{
    if(m>n)return 0;
    ll a=1,b=1;

    for(ll i=1;i<=m;i++)
    {
        a=a*(n-m+i)%p;
        b=b*i%p;
    }

    return a*qpow(b,p-2,p)%p;
}

ll lucas(ll n,ll m,ll p)
{
    if(m==0)return 1;
    
    return C(n%p,m%p,p)*lucas(n/p,m/p,p)%p;
}