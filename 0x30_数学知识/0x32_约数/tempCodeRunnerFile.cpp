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