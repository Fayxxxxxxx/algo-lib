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
const int INF=0x3f3f3f3f;

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
string begin;
string end;
cin>>begin>>end;
vector<pair<string,string>> pos;
vector<pair<string,string>> neg;
string s1,s2;
while(cin>>s1>>s2)
{
    pos.push_back({s1,s2});
    neg.push_back({s2,s1});
}

//得到变换规则了 然后用unordered_map用来存个数
int ans=-1;
unordered_map<string,int> pos_mp;
unordered_map<string,int> neg_mp;
pos_mp[begin]=0;
neg_mp[end]=0;
queue<string> pos_q;
queue<string> neg_q;

pos_q.push(begin);
neg_q.push(end);

while(!pos_q.empty()&&!neg_q.empty())
{
//先是pos
int sz=pos_q.size();
while(sz--)
{
    string pos_s=pos_q.front();
pos_q.pop();
if(pos_mp[pos_s]>=5)continue;
for(auto [from,to]:pos)
{
    size_t ps=pos_s.find(from);
    
    while(ps!=string::npos)
    {
        string t=pos_s;
        
        t.replace(ps,from.size(),to);
        ps=pos_s.find(from,ps+1);
        if(pos_mp.count(t))continue;

        pos_mp[t]=pos_mp[pos_s]+1;
        pos_q.push(t);
        if(neg_mp.count(t))
        {
            int now=pos_mp[t]+neg_mp[t];

            if(ans==-1||now<ans)
            {
                ans=now;
            }
        }
    }
}
}
sz=neg_q.size();
while(sz--)
{
string neg_s=neg_q.front();
neg_q.pop();
if(neg_mp[neg_s]>=5)continue;
for(auto [from,to]:neg)
{
    size_t ps=neg_s.find(from);
    
    while(ps!=string::npos)
    {
        string t=neg_s;
        
        t.replace(ps,from.size(),to);
        ps=neg_s.find(from,ps+1);
        if(neg_mp.count(t))continue;

        neg_mp[t]=neg_mp[neg_s]+1;
        neg_q.push(t);
        if(pos_mp.count(t))
        {
            int now=pos_mp[t]+neg_mp[t];

            if(ans==-1||now<ans)
            {
                ans=now;
            }
        }
    }
}
}
}
if(ans==-1||ans>10)
{
    cout<<"NO ANSWER!"<<endl;
}
else
{
    cout<<ans<<endl;
}

    return 0;
}