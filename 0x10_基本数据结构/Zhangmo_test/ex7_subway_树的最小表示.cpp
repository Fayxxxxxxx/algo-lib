#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int N=1e4;
int fa[N];
int son[N];
int cal(string &s)
{
    int idx=1;
    memset(son,0,sizeof(son));
    memset(fa,-1,sizeof(fa));
    
    int u=idx;
    for(char x:s)
    {
        if(x=='0')
        {
            son[u]=++idx;
            int f=u;
            u=son[u];
            fa[u]=f;
        }
        else
        {
            u=fa[u];
        }
    }
    return idx;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n;
cin>>n;
while(n--)
{
    string s1,s2;
    cin>>s1>>s2;
    
    if(cal(s1)==cal(s2))
    {
        cout<<"same"<<endl;
    }
    else
    {
        cout<<"different"<<endl;
    }
}



    return 0;
}


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
string dfs(string& s,int& idx)
{
    vector<string> sons;
    
    idx++;
    
    while(idx<s.size()&&s[idx]=='0')
    {
        sons.push_back(dfs(s,idx));
    }

    idx++;//此时s[idx]=='1'

    sort(sons.begin(),sons.end());
    string res="0";
    for(string x:sons)
    {
        res+=x;
    }
    res+="1";

    return res;
}
string get(string s)
{
    s="0"+s+"1";
    int idx=0;
    return dfs(s,idx);
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n;
cin>>n;
for(int i=0;i<n;i++)
{
    string a,b;
    cin>>a>>b;

    if(get(a)==get(b))
    {
        cout<<"same"<<endl;
    }
    else
    {
        cout<<"different"<<endl;
    }
}



    return 0;
}