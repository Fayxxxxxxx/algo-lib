#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
using vc=vector<char>;
using vb=vector<bool>;
using vs=vector<string>;
const int INF=0x3f3f3f3f;
int n;
const int N=1e5;
vi primes(N);
vb is_prime(N,true);
int cnt;
void init()
{
    is_prime[0]=false;
    is_prime[1]=false;

    for(int i=2;i<=n;i++)
    {
        if(is_prime[i])primes[cnt++]=i;

        for(int j=0;j<cnt;j++)
        {
            int x=primes[j]*i;

            if(x>n)break;

            is_prime[x]=false;

            if(i%primes[j]==0)break;
        }
    }
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n;
init();
int res=1;
for(int i=0;i<cnt;i++)
{
    int x=primes[i];
    int num=0;
    int k=n;

    while(k%x==0)
    {
        k/=x;   
        num++;
    }

    res*=(num+1);
}
cout<<res<<endl;


    return 0;
}

//下面是模板化
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
using vc=vector<char>;
using vb=vector<bool>;
using vs=vector<string>;
const int INF=0x3f3f3f3f;
vector<pair<ll,int>> fact(ll n)
{
    vector<pair<ll,int>> fac;

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
            fac.push_back({p,cnt});
        }
    }

    if(n>1)
    {
        fac.push_back({n,1});
    }
    return fac;
}

ll divisor_count(vector<pair<ll,int>> &fac)
{
    ll ans=1;
    for(auto [e,cnt]:fac)
    {
        ans*=cnt+1;
    }
    return ans;
}

ll divisor_sum(vector<pair<ll,int>> &fac)
{
    ll ans=1;
    for(auto [e,cnt] :fac)
    {
        ll cur=1;
        ll pw=1;

        for(int i=1;i<=cnt;i++)
        {
            pw*=e;
            cur+=pw;
        }

        ans*=cur;
    }
    return ans;
}
int main()
{
ios::sync_with_stdio(0);a
cin.tie(0);




    return 0;
}


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
using vc=vector<char>;
using vb=vector<bool>;
using vs=vector<string>;
const int INF=0x3f3f3f3f;

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
vi res;
int cnt=0;
for(int i=1;i<=n/i;i++)
{
    if(n%i==0)
    {
        res.push_back(i);
        cnt++;
        if(i*i!=n)
        {
          res.push_back(n/i);
          cnt++;
        }
    }
}
    return 0;
}