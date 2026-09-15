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
int n,m;
    cin>>n>>m;
    vector<vc> grid(n,vc(m));
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)cin>>grid[i][j];
    }
    vi height(m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='F')
            {
                height[j]++;
            }
            else
            {
             height[j]=0;
            }
        }
        vi left(m+1,-1);
        vi right(m+1,m);

        stack<int> st;
        for(int j=0;j<m;j++)
        {
           int h=height[j];

            while(!st.empty()&&height[st.top()]>=h)
            {
                right[st.top()]=j;
                st.pop();
            }

            if(!st.empty())
            {
                left[j]=st.top();
            }
            st.push(j);
        }

        for(int i=0;i<m;i++)
        {
            ans=max(ans,(ll)(right[i]-left[i]-1)*height[i]*3);
        }
    }
    cout<<ans<<endl;


    return 0;
}