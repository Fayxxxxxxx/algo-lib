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

ll gcd(ll a, ll b)
{
    return b?gcd(b,a%b):a;
}

ll lcm(ll a, ll b)
{
    return a/gcd(a,b)*b;
}
void solve()
{
    ll a0,a1,b0,b1;
    cin>>a0>>a1>>b0>>b1;

    int cnt=0;

    for(ll i=1;i<=b1/i;i++)
    {
        if(b1%i!=0) continue;

        // 第一个约数
        ll x=i;

        if(gcd(x,a0)==a1 && lcm(x,b0)==b1)
        {
            cnt++;
        }

        // 与 i 配对的另一个约数
        x=b1/i;

        if(x!=i &&
           gcd(x,a0)==a1 &&
           lcm(x,b0)==b1)
        {
            cnt++;
        }
    }

    cout<<cnt<<endl;
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;

while(t--)
{
    solve();
}



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

ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}

ll lcm(ll a,ll b)
{
    return a/gcd(a,b)*b;
}
ll pow(ll a,ll b)
{
    ll res=1;

    while(b)
    {
        if(b&1)res*=a;
        b>>=1;
        a=a*a;
    }
    return res;
}
vector<pair<ll,int>> get(ll x)
{
    vector<pair<ll,int>> res;
    for(ll i=2;i<=x/i;i++)
    {
        int cnt=0;

        while(x%i==0)
        {
            x/=i;
            cnt++;
        }
        if(cnt)
        {
            res.push_back({i,cnt});
        }
    }

    if(x>0)
    {
        res.push_back({x,1});
    }
    return res;
}
int cnt;
ll a0,a1,b0,b1;
void dfs(vector<pair<ll,int>> &res,ll total,int u)//提供res和现在的层数 还有现在的总和
{
 if(u==(int)res.size())
 {
   if(gcd(total,a0)==a1&&lcm(total,b0)==b1)
   {
    cnt++;
   }
   return ;
 }
  
 auto [x,num]=res[u];

 for(int e=0;e<=num;e++)
 {
   dfs(res,total+pow(x,e),u+1);
 }

}
void solve()
{
    cin>>a0>>a1>>b0>>b1;
    cnt=0;
    vector<pair<ll,int>> tmp=get(b1);
    dfs(tmp,0,0);
    cout<<cnt<<endl;

}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
ll n;
cin>>n;

while(n--)
{
    solve();
}



    return 0;
}


//最佳版本我觉得
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
const int N=1e5;
vb is_prime(N+1,true);
vi primes(N+1);
int sz;

void init()
{
    is_prime[0]=false;
    is_prime[1]=false;
    
    for(int i=2;i<=N;i++)
    {
        if(is_prime[i])primes[sz++]=i;
        
        for(int j=0;j<sz;j++)
        {
            if(primes[j]>N/i)break;
            
            ll x=primes[j]*i;

            is_prime[x]=false;
            
            if(i%primes[j]==0)break;
        }
    }
}
ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}

ll lcm(ll a,ll b)
{
    return a/gcd(a,b)*b;
}

vector<pair<ll,int>> get(ll x)
{
    vector<pair<ll,int>> res;
    for(int i=0;i<sz&&primes[i]<=x/primes[i];i++)
    {
        ll y=primes[i];
        
        int cnt=0;
        
        while(x%y==0)
        {
            x/=y;
            cnt++;
        }
        
        if(cnt)
        {
            res.push_back({y,cnt});
        }
    }

    if(x>1)
    {
        res.push_back({x,1});
    }
    return res;
}
int cnt;
ll a0,a1,b0,b1;
void dfs(vector<pair<ll,int>> &res,ll total,int u)//提供res和现在的层数 还有现在的总和
{
 if(u==(int)res.size())
 {
   if(gcd(total,a0)==a1&&lcm(total,b0)==b1)
   {
    cnt++;
   }
   return ;
 }
  
 auto [x,num]=res[u];

ll pw=1;
 for(int e=0;e<=num;e++)
 {
   dfs(res,total*pw,u+1);
   pw*=x;
 }

}
void solve()
{
    cin>>a0>>a1>>b0>>b1;
    cnt=0;
    vector<pair<ll,int>> tmp=get(b1);
    dfs(tmp,1,0);
    cout<<cnt<<endl;

}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
ll n;
cin>>n;
init();
while(n--)
{
    solve();
}



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
ll get_p(ll a,ll p)
{
    int cnt=0;
    while(a%p==0)
    {
        cnt++;
        a/=p;
    }
    return cnt;
}
vector<pair<ll,int>> get(ll a)
{
    vector<pair<ll,int>> res;
    
    for(ll i=2;i<=a/i;i++)
    {
        int cnt=0;

        if(a%i==0)
        {
            while(a%i==0)
            {
                a/=i;
                cnt++;
            }
            res.push_back({i,cnt});
        }
    }
    if(a>1)
    {
        res.push_back({a,1});
    }
    return res;
}
ll get_ways(ll a0,ll a1,ll b0, ll b1)
{
    if(b1%a1!=0)
    {
        return 0;
    }
  vector<pair<ll,int>> nums=get(b1);

  ll ans=1;
  for(auto [p,e]:nums)
  {
    int A0=get_p(a0,p);
    int A1=get_p(a1,p);
    int B0=get_p(b0,p);
    int B1=get_p(b1,p);
    
    int l=0;
    int r=B1;

    if(A1<A0)
    {
        l=max(l,A1);
        r=min(r,A1);
    }
    else
    {
        l=max(l,A1);
    }

    if(B0<B1)
    {
        l=max(l,B1);
        r=min(r,B1);
    }

    if(l>r)
    {
        return 0;
    }

    ans*=r-l+1;

  }
  return ans;
  
}
void solve()
{
   ll a0,a1,b0,b1;
   cin>>a0>>a1>>b0>>b1;

   cout<<get_ways(a0,a1,b0,b1)<<endl;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;
while(t--)
{
    solve();
}



    return 0;
}