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