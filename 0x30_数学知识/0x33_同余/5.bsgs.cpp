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
using i128=__int128_t;
const int INF=0x3f3f3f3f;
//1.存b*a^j  由定义可知a^(T*i)===b*a^j (mod p)
//而T=floor(sqrt(p)); T向上取整
//j是从0到T-1的一个数 很显然因为如果不是0-T-1的一个数那么就会归到i去
ll qpow(ll a,ll b,ll mod)
{
    ll res=1;

    while(b)
    {
        if(b&1)res=(i128)res*a%mod;
        b>>=1;
        a=(i128)a*a%mod;
    }
    return res;
}
//1.baby step
unordered_map<ll,ll> mp;
ll cur=b%p;

for(int j=0;j<T;j++)
{
mp[cur]=j;//为什么这里不用进行判断重复? 因为我们一般要求 最小的x 而x=i*t-j j大才可以求最小x
cur=(i128)cur*a%p;//i128进行过渡
}

//然后2.giant step
ll step=qpow(a,T,p);
ll cur=step;//a^T
//每次:
cur=cur*step%p;

//然后判断
mp.count(cur);

//如果找到了那么就是
a^(T*i)===b*a^j
//那么x=t*i-j
int main()
{
ios::sync_with_stdio(0);
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
using i128=__int128_t;
const int INF=0x3f3f3f3f;
ll qpow(ll a,ll b,ll mod)
{
    ll res=1;

    while(b)
    {
        if(b&1)res=(i128)res*a%mod;
        b>>=1;
        a=(i128)a*a%mod;
    }
    return res;
}

ll bsgs(ll a,ll b,ll p)
{
    a%=p;
    b%=p;

    if(b==1)
    {
        return 0;//如果b为1那么直接让x=0就可以了
    }

    ll T=ceil(sqrt(double(p)));

    unordered_map<ll,ll> mp;

    //baby step

    ll cur=b;

    for(ll j=0;j<T;j++)
    {
        mp[cur]=j;
        cur=(i128)cur*a%p;
    }

    ll step=qpow(a,T,p);

    cur=step;

    for(ll i=1;i<=T+1;i++)
    {
        auto it=mp.find(cur);
        
        if(it!=mp.end())
        {
           ll j=it->second;
           ll x=i*T-j;

           if(x>=0)
           {
            return x;
           }
        }

        cur=(i128)cur*step%p;
    }
    return -1;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
ll a,b,p;
cin>>p>>a>>b;
cout<<bsgs(a,b,p)<<endl;

    return 0;
}