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

        for(int p:primes)
        {
            if(p>n/i)break;
            min[i*p]=p;

            if(p==min[i])break;//p已经是i的最小质因数了
        }
    }
}

vector<pair<ll,int>> fact;

for(int p=2;p<=n/p;p++)
{
    if(n%p==0)
    {
        int cnt=0;

        while(n%p==0)
        {
            n/=p;
            cnt++;
        }

        fact.push_back({p,cnt});
    }

    if(n>1)
    {
        fact.push_back({n,1});
    }
}