#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
const int BASE=10000;

vector<int> mul_vector(vector<int>&a,vector<int>&b)
{
    vector<int> c(a.size()+b.size());
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<b.size();j++)
        {
            c[i+j]+=a[i]*b[j];
        }
    }
    int t=0;
    for(int i=0;i<c.size();i++)
    {
    t+=c[i];
    c[i]=t%BASE;
    t/=BASE;
    }

    while(c.size()>1&&c.back()==0)c.pop_back();
    return c;
}
vector<int> qpow(int p,int cnt)
{
vector<int> base;
int t=p;
while(t)
{
    base.push_back(t%BASE);
    t/=BASE ;
}
vector<int> res(1,1);
while(cnt)
{
    if(cnt&1)
    {
        res=mul_vector(res,base);
    }
    base=mul_vector(base,base);
    cnt>>=1;
}
return res;
}
int get(int x,int p)
{
    int ans=0;
    while(x)
    {
        ans+=x/p;
        x/=p;
    }
    return ans;
}
const int N=6e4*2;
vector<bool> is_primes(N,true);
vector<int> primes(N);
int cnt=0;

void init(int n)
{
if(n>=0)is_primes[0]=false;
if(n>=1)is_primes[1]=false;

for(int i=2;i<=n;i++)
{
    if(is_primes[i])
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
        is_primes[x]=false;

        if(i%primes[j]==0)
        {
            break;
        }
    }
}
}
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n;
cin>>n;
init(2*n);
vector<int> cnt_p(cnt);

for(int i=0;i<cnt;i++)
{
    int p=primes[i];
    cnt_p[i]=get(2*n,p)-2*get(n,p);
}
int tmp=n+1;

for(int i=0;i<cnt&&primes[i]<=tmp;i++)
{
    while(tmp%primes[i]==0)
    {
        cnt_p[i]--;
        tmp/=primes[i];
    }
}
vector<int> ans(1,1);
for(int i=0;i<cnt;i++)
{
    if(cnt_p[i]>0)
    {
        vector<int> power=qpow(primes[i],cnt_p[i]);
        ans=mul_vector(ans,power);
    }
}
cout<<ans.back();

for(int i=(int)ans.size()-2;i>=0;i--)
{
    cout<<setw(4)<<setfill('0')<<ans[i];
}
cout<<endl;

    return 0;
}