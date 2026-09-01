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
int dir[8][2]={{-1,-2},{-1,2},{1,2},{1,-2},{-2,-1},{-2,1},{2,-1},{2,1}};
string s2="111110111100*110000100000";
void solve()
{
    string s1;
    for(int i=0;i<5;i++){
        string  x;
        cin>>x;
        s1+=x;
    }
    if(s1==s2)
    {
        cout<<0<<endl;
        return ;
    }
    int ans=INT_MAX;
    unordered_map<string,int> pos_mp;
    unordered_map<string,int> neg_mp;
    queue<string> pos_q;
    queue<string> neg_q;
    pos_mp[s1]=0;
    neg_mp[s2]=0;
    pos_q.push(s1);
    neg_q.push(s2);

    while(!pos_q.empty()&&!neg_q.empty()){
        int sz=pos_q.size();
        while(sz--)
        {
            string pos_s=pos_q.front();
            pos_q.pop();
            int pos=pos_s.find('*');
            int x=pos/5;
            int y=pos%5;
            if(pos_mp[pos_s]>8)continue;
            for(int i=0;i<8;i++)
            {
                string t=pos_s;
                int nx=x+dir[i][0];
                int ny=y+dir[i][1];

                if(nx<0||nx>=5||ny<0||ny>=5)continue;
                int num=nx*5+ny;
                swap(t[pos],t[num]);
                if(pos_mp.count(t))continue;
                pos_mp[t]=pos_mp[pos_s]+1;
                pos_q.push(t);
                if(neg_mp.count(t))
                {
                    ans=min(ans,neg_mp[t]+pos_mp[t]);
                }
            }
        }
    sz=neg_q.size();
        while(sz--)
        {
            string neg_s=neg_q.front();
            neg_q.pop();
            int pos=neg_s.find('*');
            int x=pos/5;
            int y=pos%5;
            if(neg_mp[neg_s]>8)continue;
            for(int i=0;i<8;i++)
            {
                string t=neg_s;
                int nx=x+dir[i][0];
                int ny=y+dir[i][1];

                if(nx<0||nx>=5||ny<0||ny>=5)continue;
                int num=nx*5+ny;
                swap(t[pos],t[num]);
                if(neg_mp.count(t))continue;
                neg_mp[t]=neg_mp[neg_s]+1;
                neg_q.push(t);
                if(pos_mp.count(t))
                {
                    ans=min(ans,neg_mp[t]+pos_mp[t]);
                }
            }
        }
    }

if(ans>15)
{
    cout<<-1<<endl;
}
else
{
    cout<<ans<<endl;
}
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