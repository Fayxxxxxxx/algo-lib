const int N=1e5;

bool is_prime[N];

void init(int n)
{

    for(int i=0;i<=n;i++)
    {
      is_prime[i]=true;
    }
if(n>=0)is_prime[0]=false;
if(n>=1)is_prime[1]=false;

for(int i=2;i*i<=n;i++)
{
    if(is_prime[i])
    {
        for(int j=i*i;j<=n;j+=i)
        {
            is_prime[j]=false;
        }
    }
}
}