//线性筛求phi
//由公式有如果i%p==0 则phi[i*p]=phi[i]*p;
//否则phi[i*p]=phi[i]*(p-1);

vi phi(n);
vb is_prime(n);
vi primes;

void init(int n)
{
    is_prime[0]=false;
    is_prime[1]=false;
    phi[1]=1;

    for(int i=2;i<=n;i++)
    {
        if(is_prime[i])
        {
            primes.push_back(i);
            phi[i]=i-1;
        }

        for(int x:primes)
        {
            if(i>n/x)break;
            is_prime[i*x]=false;

            if(i%x==0)
            {
                phi[i*x]=phi[i]*x;
                break;
            }
            else
            {
                phi[i*x]=phi[i]*(x-1);
            }
        }
    }
}

//欧拉函数
ll phi(ll n)
{
    ll ans=n;

    for(int i=2;i<=n/i;i++)
    {
        if(n%i==0)
        {
           ans=ans*i/(i-1);

           while(n%i==0)
           {
            n/=i;
           }
        }
    }

    if(n>1)
    {
        ans=ans*n/(n-1);
    }

    return ans;
}

//exgcd

ll exgcd(ll a,ll b,ll& x,ll& y)
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


//解ax===b(mod p)的问题 还要对此进行检验
ll x,y;
ll a,b,p;
cin>>a>>b>>p;

ll d=exgcd(a,p,x,y);

if(d%b!=0)
{
    return -1;
}
x=(i128)x*d/b;
ll mod=p/d;

x=(x%mod+mod)%mod;


//裴蜀定理求解乘法逆元 则是ax===1(mod p) 所以只需要检验d是否为1即可

ll a,p;
ll x,y;
cin>>a>>p;

ll d=exgcd(a,p,x,y);

if(d!=1)
{
    return -1;
}

