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
int n;
    cin>>n;
    vll nums(n+1);
    for(int i=1;i<=n;i++)cin>>nums[i];
    stack<ll> st;
    vll ans(n+1);
    for(int i=1;i<=n;i++)
    {
        ll x=nums[i];

        while(!st.empty()&&nums[st.top()]<x)
        {
           ans[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";

    return 0;
}