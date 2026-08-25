#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

int n;
vi a;
vi mn;
vi color;
vector<vi> g;

bool dfs(int u,int c)
{
    color[u]=c;

    for(int v:g[u])
    {
        if(color[v]==-1)
        {
            if(!dfs(v,1-c))
                return false;
        }
        else if(color[v]==color[u])
        {
            return false;
        }
    }

    return true;
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

    cin>>n;

    a.resize(n+1);
    mn.resize(n+2,INT_MAX);
    color.resize(n+1,-1);
    g.resize(n+1);

    for(int i=1;i<=n;i++)
        cin>>a[i];

    for(int i=n;i>=1;i--)
        mn[i]=min(mn[i+1],a[i]);

    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[i]<a[j]&&mn[j+1]<a[i])
            {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(color[i]==-1)
        {
            if(!dfs(i,0))
            {
                cout<<0<<endl;
                return 0;
            }
        }
    }

    stack<int> s1,s2;

    int now=1;

    vector<char> ops;

    auto pop1=[&]()->bool
    {
        if(!s1.empty()&&s1.top()==now)
        {
            s1.pop();
            ops.push_back('b');
            now++;
            return true;
        }

        return false;
    };

    auto pop2=[&]()->bool
    {
        if(!s2.empty()&&s2.top()==now)
        {
            s2.pop();
            ops.push_back('d');
            now++;
            return true;
        }

        return false;
    };

    for(int i=1;i<=n;i++)
    {
        int x=a[i];

        if(color[i]==0)
        {
            while(!s1.empty()&&s1.top()<x)
            {
                if(pop1()) continue;
                pop2();
            }

            s1.push(x);
            ops.push_back('a');
        }
        else
        {
            while(pop1());

            while(!s2.empty()&&s2.top()<x)
            {
                if(pop1()) continue;
                pop2();
            }

            while(pop1());

            s2.push(x);
            ops.push_back('c');
        }
    }

    while(now<=n)
    {
        if(pop1()) continue;

        if(pop2()) continue;

        cout<<0<<endl;
        return 0;
    }

    for(int i=0;i<ops.size();i++)
    {
        if(i) cout<<" ";
        cout<<ops[i];
    }

    cout<<endl;

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
bool dfs(int u,int c,vector<vi>&g,vi &color)
{
    color[u]=c;

    for(int v:g[u])
    {
        if(color[v]==-1)
        {
            if(!dfs(v,c^1,g,color))
            {
                return false;
            }
        }
        else if(color[v]==color[u])
        {
            return false;
        }
    }
    return true;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n;
cin>>n;
vi nums(n+1);
for(int i=1;i<=n;i++)cin>>nums[i];
vi Minback(n+2);
Minback[n+1]=INT_MAX;
for(int i=n;i>=1;i--)
{
    Minback[i]=min(Minback[i+1],nums[i]);
}
vector<vi> g(n+2);

for(int i=1;i<=n;i++)
{
    for(int j=i+1;j<=n;j++)
    {
        if(nums[i]<nums[j]&&Minback[j+1]<nums[i])
        {
            g[i].push_back(j);
            g[j].push_back(i);
        }
    }
}
vi color(n+1,-1);
for(int i=1;i<=n;i++)
{
    if(color[i]==-1)
    {
        if(!dfs(i,0,g,color))
        {
            cout<<0<<endl;
            return 0;
        }
    }
}

//操作a 就是idx<=n&&color[idx]==0&&(s1.empty()||s1.top()>nums[idx]) 
//操作b 就是!s1.emtpy()&&s1.top()==now
//操作c 就是idx<=n&&color[idx]==1&&(s2.empty()||s2.top()>nums[idx])
//操作d 就是!s2.empty()&&s2.top()==now
stack<int> s1,s2;
int now=1;
int i=1;
vector<char> res;
for(int t=0;t<2*n;t++)
{
    if(i<=n&&color[i]==0&&(s1.empty()||s1.top()>nums[i]))
    {
        s1.push(nums[i]);
        i++;
        res.push_back('a');
    }
    else if(!s1.empty()&&s1.top()==now)
    {
        res.push_back('b');
        s1.pop();
        now++;
    }
    else if(i<=n&&color[i]==1&&(s2.empty()||s2.top()>nums[i]))
    {
        s2.push(nums[i]);
        i++;
        res.push_back('c');
    }
    else if(!s2.empty()&&s2.top()==now)
    {
        res.push_back('d');
        now++;
        s2.pop();
    }
}
for(char x:res)
{
    cout<<x<<" ";
}
cout<<endl;

    return 0;
}