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
const int N=1e6+10;
int cnt[N];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n;

for(int i=2;i<=n;i++)
{
 int k=i;
 for(int j=2;j<=k/j;j++)
 {
    if(k%j==0)
    {
        int num=0;

        while(k%j==0)
        {
            k/=j;
            num++;
        }

        cnt[j]+=num;
    }
 }

 if(k>1)
 {
    cnt[k]+=1;
 }
}
for(int i=2;i<=N-1;i++)
{
    if(cnt[i])
    {
        cout<<i<<" "<<cnt[i]<<endl;
    }
}


    return 0;
}



//第二种方法

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
const int N=1e6+10;
vi primes(N);
vb is_prime(N,true);
int cnt;
void init()
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
for(int i=0;i<cnt;i++)
{
    int p=primes[i];

    int x=n;
    int res=0;

    while(x)
    {
        x/=p;
        res+=x;
    }
    cout<<p<<" "<<res<<endl;
}



    return 0;
}