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

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
ll n;
cin>>n;
vll height(n+1);
for(int i=0;i<n;i++)
{
    cin>>height[i];
}
    height[n]=LLONG_MAX;
    vll ans(n);
    stack<ll> st;
    for(int i=0;i<n+1;i++)
    {
        ll h=height[i];

        while(!st.empty()&&height[st.top()]<=h)
        {
            ans[st.top()]=i-st.top()-1;
            st.pop();
        }
        st.push(i);
    }
    
    ll total=0;
    for(ll x:ans)total+=x;
    cout<<total<<endl;
    

    return 0;
}   