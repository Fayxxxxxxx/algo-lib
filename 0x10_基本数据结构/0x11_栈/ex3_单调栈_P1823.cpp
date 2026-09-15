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
    vll height(n);
    for(int i=0;i<n;i++)cin>>height[i];

    stack<pair<ll,ll>> st;
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        ll h=height[i];

        while(!st.empty()&&st.top().first<h)
        {
            ans+=st.top().second;
            st.pop();
        }
        if(!st.empty()&&st.top().first==h)
        {
            ans+=st.top().second;

            if(st.size()>1)
            {
                ans++;
            }
            st.top().second++;
        }
        else if(!st.empty())
        {
            ans++;
            st.push({h,1});
        }
        else if(st.empty())
        {
            st.push({h,1});
        }
    }
    cout<<ans<<endl;


    return 0;
}