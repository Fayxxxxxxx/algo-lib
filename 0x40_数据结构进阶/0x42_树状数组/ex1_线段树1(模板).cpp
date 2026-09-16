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
const int N=1e5+5;
int n,m;
void add(vll& tr,ll x,ll k)
{
    while(x<=n)
    {
        tr[x]+=k;
        x+=x&-x;
    }
}
ll query(vll& tr,ll x)
{
    ll res=0;
    while(x)
    {
        res+=tr[x];
        x-=x&-x;
    }
    return res;
}
vll tr1(N,0);//第一个数组是正常的tr
vll tr2(N,0);//第二个数组是i*bi的
ll sum(ll x)
{
    return query(tr1,x)*(x+1)-query(tr2,x);
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n>>m;
    vll diff(n+1);
    vll nums(n+1);

    for(int i=1;i<=n;i++)cin>>nums[i];

    for(int i=1;i<=n;i++)
    {
        add(tr1,i,nums[i]-nums[i-1]);
        add(tr2,i,(nums[i]-nums[i-1])*i);
    }
    for(int i=0;i<m;i++)
    {
        int op;
        cin>>op;

        if(op==1)
        {
            ll x,y,k;
            cin>>x>>y>>k;
            add(tr1,x,k);
            add(tr1,y+1,-k);

            add(tr2,x,k*x);
            add(tr2,(y+1),-k*(y+1));
        }
        else
        {
            ll x,y;
            cin>>x>>y;

            cout<<sum(y)-sum(x-1)<<endl;
        }
    }

    return 0;
}