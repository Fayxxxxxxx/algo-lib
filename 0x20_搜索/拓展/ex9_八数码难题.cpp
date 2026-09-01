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
int dir[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
//我利用双向BFS来求解这个问题
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
string end="123804765";
string begin;
cin>>begin;
bool flag=false;
int ans=0;
if(begin==end)
{
    cout<<0<<endl;
    return 0;
}
unordered_map<string,int> pos_mp;
unordered_map<string,int> neg_mp;
queue<string> pos_q;
queue<string> neg_q;
pos_mp[begin]=0;
neg_mp[end]=0;
pos_q.push(begin);
neg_q.push(end);
while(!pos_q.empty()&&!neg_q.empty()&&!flag)
{
    int sz=pos_q.size();
    while(sz--&&!flag)
    {
        string pos_s=pos_q.front();
        pos_q.pop();

        int pos=pos_s.find('0');
        int x=pos/3;
        int y=pos%3;

        for(int i=0;i<4;i++)
        {
            string t=pos_s;
            int nx=x+dir[i][0];
            int ny=y+dir[i][1];

            if(nx<0||nx>=3||ny<0||ny>=3)continue;
            int p=nx*3+ny;
            swap(t[p],t[pos]);
            if(pos_mp.count(t))continue;
            pos_mp[t]=pos_mp[pos_s]+1;
            pos_q.push(t);
            if(neg_mp.count(t))
            {
                ans=pos_mp[t]+neg_mp[t];
                flag=true;
                break;
            }
        }
    }
    sz=neg_q.size();
    while(sz--&&!flag)
    {
        string neg_s=neg_q.front();
        neg_q.pop();

        int pos=neg_s.find('0');
        int x=pos/3;
        int y=pos%3;

        for(int i=0;i<4;i++)
        {
            string t=neg_s;
            int nx=x+dir[i][0];
            int ny=y+dir[i][1];

            if(nx<0||nx>=3||ny<0||ny>=3)continue;
            int p=nx*3+ny;
            swap(t[p],t[pos]);
            if(neg_mp.count(t))continue;
            neg_mp[t]=neg_mp[neg_s]+1;
            neg_q.push(t);
            if(pos_mp.count(t))
            {
                ans=pos_mp[t]+neg_mp[t];
                flag=true;
                break;
            }
        }
    }
}
cout<<ans<<endl;


    return 0;
}