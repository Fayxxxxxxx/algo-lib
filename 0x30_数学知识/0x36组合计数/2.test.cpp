//1.首先是一般
int N=2010;
int C[N][N];

int nums(int n,int m)
{
    for(int i=1;i<=N;i++)
    {
        C[i][0]=1;

        for(int j=1;j<=i;j++)
        {
            C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }

    return C[n][m];
}


//2.第二种写法逆元
ll mod=1e9+7;
ll qpow(ll a,ll b)
{
 ll res=1;

 while(b)
 {
    if(b&1)res=res*a%mod;
    b>>=1;
    a=a*a%mod;
 }
 return res;
}
int n=1e5;
vll fact(n+5);
vll invfact(n+5);
ll inv(ll a)
{
    return qpow(a,mod-2);
}
ll C(ll n,ll m)
{
    return fact[n]%mod*invfact[n-m]%mod*invfact[m]%mod;
}
int main()
{
    fact[0]=1;

    for(int i=1;i<=n;i++)
    {
        fact[i]=fact[i-1]*i%mod;
    }
    
    invfact[n]=inv(fact[n]);
    for(int i=n-1;i>=0;i--)
    {
        fact[i]=fact[i+1]*(i+1)%mod
    }
    
}



//3.第三种分解质因数 一般这种情况就要去用到高精度了 而且有些时候还要压位 也就是取余数从10改为10000等
//线性筛
const int N=1e5;
vi primes;
vb is_prime(N,true);

void init(int n)
{
    is_prime[0]=false;
    is_prime[1]=false;

   for(int i=2;i<=n;i++)
   {
    if(is_prime[i])primes.push_back(i);

    for(int p:primes)
    {
        if(i>n/p)break;
        is_prime[i*p]=true;
        if(i%p==0)break;
    }
   }
}
ll get_p(ll a,ll p)
{
    ll res=0;

    while(a)
    {
        res+=a/p;
        a/=p;
    }
    return res;
}

ll get(ll n,ll m)
{
    if(m<0||m>n)return 0;

    m=min(m,n-m);

    init(n);x
    ll ans=1;

    for(int p:primes)
    {
        int e=get_p(n,p)-get_p(n-m,p)-get_p(m,p);

        while(e--)
        {
            ans*=p;
        }
    }

    return ans;
}
