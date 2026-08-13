//三次遍历 

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'


signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n;
while(cin>>n&&n)
{
vector<int> heights(n);
for(int i=0;i<n;i++)cin>>heights[i];

        vector<int> left(n,-1);
        vector<int> right(n,n);

        stack<int> left_st;

        for(int i=0;i<n;i++)
        {
            int h=heights[i];
            while(!left_st.empty()&&h<=heights[left_st.top()])
            {
                left_st.pop();
            }
            if(!left_st.empty()){
                left[i]=left_st.top();
            }
            left_st.push(i);

        }

        stack<int> right_st;
        for(int i=n-1;i>=0;i--)
        {
            int h=heights[i];
            while(!right_st.empty()&&h<=heights[right_st.top()])
            {
                right_st.pop();
            }
            if(!right_st.empty())
            {
                right[i]=right_st.top();
            }
            right_st.push(i);
        }

        int ans=0;

        for(int i=0;i<n;i++)
        {
            ans=max(ans,heights[i]*(right[i]-left[i]-1));
        }
        cout<<ans<<endl;
}

    return 0;
}

//两次遍历
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'


signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n;
while(cin>>n&&n)
{
vector<int> heights(n);
for(int i=0;i<n;i++)cin>>heights[i];

        vector<int> left(n,-1);
        vector<int> right(n,n);

         stack<int> st;
        for(int i=0;i<n;i++)
        {
            int h=heights[i];
            while(!st.empty()&&h<=heights[st.top()])
            {
                right[st.top()]=i;
                st.pop();
            }
            if(!st.empty())
            {
                left[i]=st.top();
            }
            st.push(i);
        }

        int ans=0;

        for(int i=0;i<n;i++)
        {
            ans=max(ans,heights[i]*(right[i]-left[i]-1));
        }
        cout<<ans<<endl;
}

    return 0;
}

