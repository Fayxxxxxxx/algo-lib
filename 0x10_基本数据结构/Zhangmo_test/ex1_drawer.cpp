//1.括号画家
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
struct node
{
  char elem;
   int id;
};
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
unordered_map<char,char> mp;
mp[']']='[';
mp[')']='(';
mp['}']='{';
string s;
    cin>>s;
    stack<node> st;
    int ans=0;
    int last=-1;
    for(int i=0;i<s.size();i++)
    {
        if(!mp[s[i]])
        {
            st.push({s[i],i});
        }
        else
        {
           if(!st.empty()&&st.top().elem==mp[s[i]])
           {
               st.pop();

               if(st.empty())
               {
                   ans=max(ans,i-last);//不一定是第0位开始 所以有个last
               }
               else
               {
                  ans=max(ans,i-st.top().id);
               }
           }
            else
            {
               while(!st.empty())
               {
                   st.pop();
               }
                last=i;
            }
        }
    }
    cout<<ans<<endl;
    


    return 0;
}