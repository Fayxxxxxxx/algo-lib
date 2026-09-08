//1.快速幂
ll qpow(ll a,ll b,ll mod)
{
    ll res=1;

    while(b)
    {
        if(b&1)res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res%mod;
}


//2.exgcd
ll exgcd(ll a,ll b,ll&x,ll& y)
{
    if(b==0)
    {
        x=1;
        y=0;

        return a;
    }

    ll x1,y1;

    ll d=exgcd(b,a%b,x1,y1);

    x=y1;
    y=x1-a/b*y1;

    return d;
}

//ax+by=c的求解 可以先求ax+by=gcd(x,y) 如果求解的值c%d!=0则return false;

bool solve(ll a,ll b,ll c,ll&x,ll& y)
{
 ll d=exgcd(a,b,x,y);

 if(c%d!=0)
 {
    return false;
 }

 x*=c/d;
 y*=c/d;

 return true;
}


//3.exgcd求解逆元 求a的-1===1(mod n) n不保证为质数的情况下(如果是质数我就直接使用费马小定理了)
//那么就是去求解ax===1(mod n)x的解 而这个可以翻译为ax+ny=1 然后把a换入 n换入求解x
//并且由于x有可能为负数 所以要加上mod再取余mod

ll inv_exgcd(ll a,ll n)
{
    ll x,y;

    ll d=exgcd(a,n,x,y);

    if(d!=1)
    {
        return -1;
    }

    return (x%n+n)%n;
}


//4.费马小定理求解逆元 只需要快速幂且第二位放入p-2 保证p是个质数即可

ll inv_prime(ll a,ll mod)
{
    return  qpow(a,mod-2);
}

//5.求解线性同余方程 ax===b(mod m); 那么就是
bool solve(ll a,ll b,ll m,ll &x)
{
    ll y;

    ll d=exgcd(a,m,x,y);

    if(b%d!=0)
    {
        return false;
    }

    x*=b/d;
    ll period=m/d;
    x=(x%period+period)%period;

    return true;
}