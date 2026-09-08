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
const int N=1e3+10;
vll primes;
vb is_prime(N+5,true);
vll phi(N+5);
void init()
{
  phi[1]=1;
  is_prime[0]=false;
  is_prime[1]=false;
  
  for(int i=2;i<=N;i++)
  {
      if(is_prime[i]){
          phi[i]=i-1;
          primes.push_back(i);
      }
      for(int p:primes)
      {
          if(i>N/p)break;
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
void solve()
{
    int n;
    cin>>n;
    cout<<n<<" ";
    ll total=0;
    for(int i=1;i<=n;i++)
    {
        total+=2*phi[i];
    }
    cout<<total+1<<endl;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
init();
int t;
cin>>t;
int tt=1;
while(t--)
{
    cout<<tt<<" ";
    solve();
    tt++;
}




    return 0;
}