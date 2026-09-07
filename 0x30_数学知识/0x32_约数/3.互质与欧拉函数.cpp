//互质就是gcd(a,b)==1

//欧拉函数就是求1~n中有多少个数与n是互质的
//公式是欧拉(n)=n*(1-1/p)(所有质因数的)
ll ans=n;
for(int i=2;i<=n/i;i++)
{
 if(n%i==0)
 {
    ans=ans/i*(i-1);

    while(n%i==0)
    {
        n/=i;
    }
 }

 if(n>1)
 {
    ans=ans/n*(n-1);
 }
}


vi phi(n+1);
vb is_prime(n+1,true);
vi primes;
void init(int n)
{
    phi[1]=1;
    is_prime[0]=false;
    is_prime[1]=false;

    for(int i=2;i<=n;i++)
    {
        if(is_prime[i])
        {
          primes.push_back(i);
          phi[i]=i-1;
        }

        for(int p:primes)
        {
            if(p>=n/i)break;

            is_prime[i*p]=false;

            if(i%p==0)
            {
                phi[i*p]=phi[i]*p;
                break;
            }
            else
            {
                phi[i*p]=phi[i]*(p-1);
            }
        }
    }
}


//完整和线性筛结合
vector<int> primes;
vector<int> phi(N+1);
vector<bool> is_prime(N+1,true);

void init()
{
    is_prime[0]=is_prime[1]=false;
    phi[1]=1;

    for(int i=2;i<=N;i++)
    {
        if(is_prime[i])
        {
            primes.push_back(i);
            phi[i]=i-1;
        }

        for(int p:primes)
        {
            if(p>N/i)break;

            is_prime[i*p]=false;

            if(i%p==0)
            {
                phi[i*p]=phi[i]*p;
                break;
            }

            phi[i*p]=phi[i]*(p-1);
        }
    }
}
