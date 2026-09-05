//利用映射的方法 1.n如果是个合数 必然有个<=根号n的质数 
//这里还用到了向上整除的的方法 a/b向上整除=(a+b-1)/b 其实还是很好理解的
//但凡a%b所留的余数>=1 那么都可以向上进一位 如果没有那么就向上取整不了

//这里对last的使用也有必要学习一下 
//这个方法将1e9的R 通过开根号将为1e5 所以是个非常好的方法 区间筛
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
ll l,r;
const int N=1e5+10;
int cnt;
vb is_prime(N+1,true);
vi primes(N+1);
void init()
{
    is_prime[0]=false;
    is_prime[1]=false;
    
    for(int i=2;i<=N;i++)
    {
        if(is_prime[i])
        {
            primes[cnt++]=i;
        }
        
        for(int j=0;j<cnt;j++)
        {
            int x=primes[j]*i;
            
            if(x>N)break;
            
            is_prime[x]=false;
            
            if(i%primes[j]==0)break;
        }
    }
}

void solve()
{
    vb st(r-l+1,false);//为false说明是质数 true不是质数
    for(int i=0;i<cnt;i++)
    {
        ll p=primes[i];
        
        if(p*p>r)break;
        
        ll start=max(p*p,(l+p-1)/p*p);
        
        for(ll i=start;i<=r;i+=p)st[i-l]=true;
    }
    
    if(l==1)st[0]=true;
    
    int last=-1;
    int c1=0,c2=0;
    int d1=0,d2=0;
    ll max_gap=-1;
    ll min_gap=LLONG_MAX;
    
    for(int i=l;i<=r;i++)
    {
        if(st[i-l])continue;
        
        if(last!=-1)
        {
            ll gap=i-last;
            
            if(gap<min_gap)
            {
                c1=last;
                c2=i;
                min_gap=gap;
            }
            
            if(gap>max_gap)
            {
                d1=last;
                d2=i;
                max_gap=gap;
            }
        }
        last=i;
    }
    if(max_gap==-1)
    {
        cout<<"There are no adjacent primes."<<endl;
    }
    else
    {
        cout<<c1<<","<<c2<<" are closest, "<<d1<<","<<d2<<" are most distant."<<endl;
    }
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
init();
while(cin>>l>>r)
{
    solve();
}



    return 0;
}