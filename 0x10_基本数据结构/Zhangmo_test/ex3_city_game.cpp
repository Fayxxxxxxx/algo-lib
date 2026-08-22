#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n,m;
cin>>n>>m;
vector<vector<char>> grid(n,vector<char>(m));
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)cin>>grid[i][j];
}
vi h(m,0);
int ans=0;
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        if(grid[i][j]=='F')h[j]++;
        else
        {
            h[j]=0;
        }
    }

        vi left(m,-1);
        vi right(m,m);
        stack<int> st;

        for(int j=0;j<m;j++)
        {
            while(!st.empty()&&h[j]<=h[st.top()])
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

        for(int j=0;j<m;j++)
        {
            ans=max(ans,(right[j]-left[j]-1)*h[j]);
        }
        
}
cout<<ans*3<<endl;
    return 0;
}