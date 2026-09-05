unordered_map<int,int> mp;
void solve(int n)
{
    for(int i=2;i<=n/i;i++)
    {
        if(n%i==0)
        {
            int cnt=0;

            while(n%i==0)
            {
                n/=i;
                cnt++;
            }

            mp[i]=cnt;
        }
    }

    if(n>1)
    {
        mp[n]=1;
    }
}


vector<int> primes;
vector<int> minp(N+1);

void init()
{
    for(int i=2;i<=N;i++)
    {
        if(minp[i]==0)
        {
            minp[i]=i;
            primes.push_back(i);
        }

        for(int x:primes)
        {
            if(x>minp[i])break;
            if(x>N/i)break;

            minp[i*x]=x;
        }
    }
}