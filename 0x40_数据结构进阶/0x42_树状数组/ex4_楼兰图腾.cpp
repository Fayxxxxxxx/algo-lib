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
const int N=2e5+5;

vll nums;
vll a;
int n;
ll query(vi& tr,ll x)
{
   ll res=0;
   while(x){
    res+=tr[x];
    x-=x&-x;
   }
   return res;
}
void add(vi& tr,ll x)
{
 while(x<=n){
    tr[x]+=1;
    x+=x&-x;
 }
}
ll get(ll x)
{
    return (ll)(lower_bound(nums.begin(),nums.end(),x)-nums.begin())+1;
}
vi tr1(N);
vi tr2(N);
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n;
nums.resize(n);
a.resize(n);

for(int i=0;i<n;i++)
{
cin>>nums[i];
a[i]=nums[i];
}
sort(nums.begin(),nums.end());
nums.erase(unique(nums.begin(),nums.end()),nums.end());
vll left(n);
vll right(n);

for(int i=0;i<n;i++)
{
    ll x=a[i];
    int pos=get(x);

    left[i]=i-query(tr1,pos);
    add(tr1,pos);
}
tr1.assign(n,0);
for(int i=n-1;i>=0;i--)
{
    ll x=a[i];
    int pos=get(x);

    right[i]=n-1-i-query(tr1,pos);
    add(tr1,pos);
}
ll ans=0;
for(int i=0;i<n;i++)
{
    ans+=(left[i]*right[i]);
}
cout<<ans<<" ";
ans=0;
left.assign(n,0);
right.assign(n,0);

for(int i=0;i<n;i++)
{
    ll x=a[i];
    int pos=get(x-1);

    left[i]=query(tr2,pos-1);
    add(tr2,pos);
}
tr2.assign(n,0);//assign前面是长度 后面是value
for(int i=n-1;i>=0;i--)
{
    ll x=a[i];
    int pos=get(x);

    right[i]=query(tr2,pos-1);//pos-1 
    //这样才能去访问<=pos-1 也就是<pos 的数的个数
    //我刚开始以为是pos=get(x-1) 但是实际上 x-1是不一定存在的
    add(tr2,pos);
}
for(int i=0;i<n;i++)
{
    ans+=(left[i]*right[i]);
}
cout<<ans<<endl;

    return 0;
} 