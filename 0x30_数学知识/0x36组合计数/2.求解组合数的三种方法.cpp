//1.n比较小 如n<=2000
const int N=2010;
const int mod=1e9+7;
//利用公式C(n,m)=C(n-1,m-1)+C(n-1,m);
int C[N][N];

void init()
[
    for(int i=0;i<N;i++)
    {
        C[i][0]=1;

        for(int j=1;j<=i;j++)
        {
            C[i][j]=(C[i-1][j-1]%mod+C[i-1][j]%mod)%mod;
        }
    }
]
//简单的预处理 O(n^2);

//2.n m很大 但模质数:阶乘+逆元
//n<=1e5/1e6;
//mod为质数 如1e9+7 9901; n<p
//C(n,m)=(n!)/((n-m)!*m!);
int N=1e5;
vll fact[N+1];
int mod=1e9+7;
int qpow(int a,int b)
{
    int res=1;

    while(b)
    {
        if(b&1)res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

int inv(int a)
{
    return qpow(a,mod-2);
}
fact[0]=1;
for(int i=1;i<=N;i++)
{
    fact[i]=fact[i-1]*i%mod;
}
vll invfact[N+1];
invfact[N]=inv(fact[N]);
for(int i=N-1;i>=0;i--)
{
    invfact[i]=invfact[i+1]*(i+1)%mod;
}

ll C(int n,int m)
{
    if(m<0||m>n)return 0;

    return fact[n]*invfact[n-m]%mod*invfact[m]; 
}



//质因数求组合数
//质因数分解+vp(n!);
int N;
vector<int> primes;
vector<bool> vis(N+5,true);

void get_primes(int n)
{
    vis.resize(n+1);
    vis[0]=false;
    vis[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(vis[i])
        {
            primes.push_back(i);
        }

        for(int p:primes)
        {
            if(p>n/i)break;
            vis[p*i]=false;

            if(i%p==0)break;
        }
    }
}

int get(int n,int p)
{
    int ans=0;

    while(n)
    {
        ans+=n/p;
        n/=p;
    }

    return res;
}

for(int p:pirmes)
{
    int e=get(n,p)-get(m,p)-get(n-m,p);
}