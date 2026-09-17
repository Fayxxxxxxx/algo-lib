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
const int N=5e5+5;
vi nums;
vi a;
int tr[N];
int n;
int m;
int get(int x)
{
    return (int)(lower_bound(nums.begin(),nums.end(),x)-nums.begin())+1;
}
void add(int x)
{
    while(x<=n)
    {
        tr[x]+=1;
        x+=x&-x;
    }
}
ll query(int x){
    ll res=0;
    while(x)
    {
        res+=tr[x];
        x-=x&-x;
    }
    return res;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
    cin>>n;
    nums.resize(n);
    a.resize(n);

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        nums[i]=a[i];
    }
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        int x=a[i];

        ll pos=query(get(x));
        add(get(x));
        ans+=i-pos;
    }
    cout<<ans<<endl;
    return 0;
}