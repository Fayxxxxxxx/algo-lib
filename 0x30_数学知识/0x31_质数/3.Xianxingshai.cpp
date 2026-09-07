const int N=1e5+5;

vector<int> primes(N);

vector<int> is_prime(N);

int cnt=0;

void init(int n)
{
    for(int i=0;i<=n;i++){
        is_prime[i]=true;
    }

    is_prime[0]=false;
    is_prime[1]=false;

    for(int i=2;i<=n;i++)
    {
        if(is_prime[i])
        {
            primes[cnt++]=i;
        }

        for(int j=0;j<cnt;j++)
    {
        int x=i*primes[j];

        if(x>n)
        {
            break;
        }

        is_prime[x]=false;

        if(i%primes[j]==0)//不能和其他质数配
        {
            break;
        }

    }
    }

    
}



const int N=1e5;
vector<bool> is_prime(N,true);
vector<int> primes(N);

void init(int n)
{
    int cnt=0;
    is_prime[0]=false;
    is_prime[1]=false;

    for(int i=2;i<=n;i++)
    {
        if(is_prime[i])
        {
            primes[cnt++]=i;
        }

        for(int j=0;j<cnt;j++)
        {
            int x=i*primes[j];

            if(x>n)
            {
                break;
            }

            is_prime[x]=false;

            if(i%primes[j]==0)
            {
                break;
            }
        }
    }
}


const int N=1e5;
int cnt;
int primes[N];
vb is_prime(N,true);

void init(int n)
{
    is_prime[0]=false;
    is_prime[1]=false;

    for(int i=2;i<=n;i++)
    {
        if(is_prime[i])
        {
            primes[cnt++]=i;
        }

        for(int j=0;j<cnt;j++)
        {
            int x=primes[j]*i;

            if(x>n)
            {
                break;
            }

            is_prime[x]=true;

            if(i%primes[j]==0)//线性筛一直筛到自己的最小公因子为止 然后后面的就
            //不做了 因为后面是别人的最小共因子了 
            {
                break;
            }
        }
    }
}



is_prime[0]=false;
is_prime[1]=false;


for(int i=2;i<=n;i++)
{
    if(is_prime[i])
    {
        primes.push_back(i);
    }

    for(int p:primes)
    {
        if(p>=n/i)break;

        is_prime[p*i]=false;

        if(i%p==0)break;
    }
}



minp;

for(int i=2;i<=n;i++)
{
    if(minp[i]==0)
    {
        minp[i]=i;//质数本身的最小质因数就是他自己
        primes.push_back(i);
    }

    for(int p:pirmes)
    {
        if(p>=n/i)break;

        minp[i*p]=p;

        if(p==min[i])break;
    }
}

//适用于小数很多
vector<pair<ll,int>> fact;

while(n>1)
{
    int e=0;
    int p=minp[n];

    while(n%p==0)
    {
        e++;
        n/=p;
    }

    fact.push_back({p,e});
}
return res;