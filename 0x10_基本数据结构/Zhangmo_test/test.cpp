#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

struct num
{
  int val;
  int id;
};

bool cmp(num&a,num&b)
{
    return a.val<b.val;
}
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n;
cin>>n;
vector<num> nums(n);
for(int i=0;i<n;i++)
{
    cin>>nums[i].val;
    nums[i].id=i+1;
}
sort(nums.begin(),nums.end(),cmp);

bool flag=false;//降序
int ans=1;//刚开始假设有一个
int last=INT_MAX;
for(int i=0;i<n;)
{
    int j=i;
    int maxx=0;
    int minx=INT_MAX;
    
    while(j<n&&nums[j].val==nums[i].val)
    {
        maxx=max(maxx,nums[j].id);
        minx=min(minx,nums[j].id);
        j++;
    }
    
    if(!flag)
    {
        if(maxx<last)
        {
            last=minx;
        }
        else
        {
            flag=true;
            last=maxx;
        }
    }
    else
    {
        if(minx>last)
        {
            last=maxx;
        }
        else
        {
            flag=false;
            ans++;
            last=minx;
        }
    }
    i=j;
}
cout<<ans<<endl;


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


struct run
{
    ll end;
    ll l,r;
    bool operator<(const run& a)const
    {
        return end>a.end;
    }
};
struct elem
{
  ll t,m,p;  
};
ll Max_time=0;
int cnt=0;
priority_queue<run> use;
set<pll> mem;
queue<elem> wait;
pll get_num(ll need)
{
    for(auto it=mem.begin();it!=mem.end();it++)
    {
        ll l=it->first;
        ll r=it->second;

        if(r-l+1>=need)
        {
            mem.erase(it);

            if(l+need<=r)
            {
                mem.insert({l+need,r});
            }
            return {l,l+need-1};
        }
    }
    return {-1,-1};
}
void free_mem(ll l,ll r)
{
    auto it=mem.lower_bound({l,LLONG_MIN});

    if(it!=mem.begin())
    {
        auto pre=prev(it);
        if(pre->second+1==l)
        {
            l=pre->first;
            mem.erase(pre);
        }
    }
    it=mem.lower_bound({l,LLONG_MIN});
     
    if(it!=mem.end()&&r+1==it->first)
    {
        r=it->second;
        mem.erase(it);
    }
    mem.insert({l,r});
}
bool work_in(elem x,ll now)
{
pll pos=get_num(x.m);

if(pos.first==-1)
{
    return false;
}

ll ed=x.p+now;
use.push({ed,pos.first,pos.second});
Max_time=max(Max_time,ed);

return true;
}
void work_out(ll now)
{
while(!use.empty()&&use.top().end==now)
{
    auto e=use.top();
    use.pop();
    free_mem(e.l,e.r);
}

while(!wait.empty())
{
    elem x=wait.front();

    if(work_in(x,now))
    {
        wait.pop();
    }
    else
    {
        break;
    }
}

if(!use.empty()&&use.top().end==now)
{
    work_out(now);
}
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n;
cin>>n;
ll t,m,p;
mem.insert({0,n-1});
while(cin>>t>>m>>p&&(t||m||p))
{
    while(!use.empty()&&use.top().end<=t)
    {
        ll now=use.top().end;
        work_out(now);
    }

    elem x={t,m,p};

    if(!work_in(x,t))
    {
        wait.push(x);
        cnt++;
    }
}

while(!use.empty())
{
    ll now=use.top().end;
    work_out(now);
}

cout<<Max_time<<endl;
cout<<cnt<<endl;



    return 0;
}