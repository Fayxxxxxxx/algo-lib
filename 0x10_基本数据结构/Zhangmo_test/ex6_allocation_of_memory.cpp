//一坨
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
struct elem
{
int t,m,p;
};
struct block
{
int l;
int m;
ll end;
int id;
};
bool cmp(block&a,block&b)
{
    return a.l<b.l;
}
int find_pos(vector<block>&mem,int need,int n)
{
    int pos=0;
    for(auto &e:men)
    {
        if(e.l-pos>=need){
         return pos;
        }
        else
        {
            pos=e.l+e.m;
        }
    }
    if(n-pos>=need)//到末尾了
    {
      return pos;
    }
    return -1;
}
int idcnt=0;
bool allocate(elem x,ll now,vector
<block>&mem,priority_queue<pll,vector<pll>,greater<pll>>&use,int n)
{
    int pos=find_pos(mem,x.m,n);

    if(pos==-1)
    {
        return false;
    }

    int id=idcnt++;
    mem.push_back({pos,x.m,now+x.p,id});
    sort(mem.begin(),mem.end(),cmp);
    use.push({now+x.p,id});
    return true;
}
void erase_block(vector<block>&mem,int id)
{
    for(int i=0;i<mem.size();i++)
    {
        if(mem[i].id==id)
        {
            mem.erase(mem.begin()+i);
            return ;
        }
    }
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n;
cin>>n;//从0 到n-1
int t,m,p;
vector<elem> nums;
int Max_t=0;
while(cin>>t>>m>>p&&(t||m||p))
{
    nums.push_back({t,m,p});
    Max_t=max(Max_t,t+p);
}
queue<elem> q;
vector<block> mem;//当前正在占用内存的所有地址块
priority_queue<elem,vector<elem>,cmp> use;
int cnt=0;
int Max_time=Max_t;
int now=0;

    while(!use.empty()&&use.top().t+use.top().p<=k)
    {
        surplus+=use.top().m;
        use.pop();
    }
    while(!q.empty())
    {
        elem x=q.front();
        if(allocate(x,now,mem,use,n))
        {
            q.pop();
        }
        else
        {
            break;
        }
    }
    if(nums[now].t==k){
       int pos=find_pos(mem,x.m,n)
        if(pos!=-1)
        {
          surplus-=nums[now].m;
          use.push(nums[now]);
        }
        else
        {
          cnt++;
          q.push(nums[now]);
        }
        now++;
    }

cout<<Max_time<<endl;
cout<<cnt<<endl;


    return 0;
}






//正确

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

struct elem
{
    ll t,m,p;
};

struct run
{
    ll end;
    ll l,r;

    bool operator<(const run &x)const
    {
        return end>x.end;
    }
};

ll n;

// 当前所有空闲内存区间
set<pll> mem;

// 正在运行的进程
priority_queue<run> use;

// 等待队列
queue<elem> q;

// 找最左边长度 >= need 的空闲区间
pll get_mem(ll need)
{
    for(auto it=mem.begin();it!=mem.end();it++)
    {
        ll l=it->first;
        ll r=it->second;

        if(r-l+1>=need)
        {
            mem.erase(it);

            // 剩余部分重新放回去
            if(l+need<=r)
            {
                mem.insert({l+need,r});
            }

            return {l,l+need-1};
        }
    }

    return {-1,-1};
}

// 释放区间，并与左右空闲区间合并
void free_mem(pll x)
{
    ll l=x.first;
    ll r=x.second;

    auto it=mem.lower_bound({l,-1});

    // 看左边能不能合并
    if(it!=mem.begin())
    {
        auto pre=prev(it);

        if(pre->second+1==l)
        {
            l=pre->first;
            mem.erase(pre);
        }
    }

    // 看右边能不能合并
    it=mem.lower_bound({l,-1});

    if(it!=mem.end()&&r+1==it->first)
    {
        r=it->second;
        mem.erase(it);
    }

    mem.insert({l,r});
}

// 在 now 时刻处理等待队列
void work_wait(ll now)
{
    while(!q.empty())
    {
        elem x=q.front();

        pll p=get_mem(x.m);

        if(p.first==-1)
        {
            // 队头都放不进去，后面不能插队
            break;
        }

        q.pop();

        use.push({now+x.p,p.first,p.second});
    }
}

// 处理所有 end <= t 的结束事件
void work_out(ll t)
{
    while(!use.empty()&&use.top().end<=t)
    {
        ll now=use.top().end;

        // 同一时刻结束的全部先释放
        while(!use.empty()&&use.top().end==now)
        {
            free_mem({use.top().l,use.top().r});
            use.pop();
        }

        // 再处理等待队列
        work_wait(now);
    }
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

    cin>>n;

    // 一开始整段内存全空闲
    mem.insert({0,n-1});

    ll t,m,p;

    int cnt=0;
    ll ans=0;

    while(cin>>t>>m>>p&&(t||m||p))
    {
        // 当前申请到来之前，
        // 所有已经结束的进程先处理
        work_out(t);

        elem x={t,m,p};

        // 尝试直接分配
        pll pos=get_mem(m);

        if(pos.first!=-1)
        {
            use.push({t+p,pos.first,pos.second});
        }
        else
        {
            q.push(x);
            cnt++;
        }
    }

    // 输入结束以后继续处理系统
    while(!use.empty())
    {
        ll now=use.top().end;

        ans=max(ans,now);

        while(!use.empty()&&use.top().end==now)
        {
            free_mem({use.top().l,use.top().r});
            use.pop();
        }

        work_wait(now);
    }

    cout<<ans<<endl;
    cout<<cnt<<endl;

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
struct elem
{
ll t;
ll m;
ll p;
};
struct run
{
ll end;
ll l,r;

bool operator<(const run& x)const 
{
    return end>x.end;
}
};
ll n;
ll Max_time=0;
int cnt=0;

set<pll> mem;
priority_queue<run> use;
queue<elem> q;
pll get_mem(ll need)
{
    for(auto it=mem.begin(),it!=mem.end();it++)
    {
        ll l=it->left;
        ll r=it->right;

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
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

cin>>n;
ll t,m,p;
while(cin>>t>>m>>p&&(t||m||p))
{
while(use.top().end<=t)
{
    ll now=use.top().endl;

    release_all(now);

    while(!q.empty())
    {
        if(insert(q.front(),now))
        {
            q.pop();
        }
        else
        {
            break;
        }
    }
}

if(insert())
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

struct elem
{
    ll t,m,p;
};

struct run
{
    ll end;
    ll l,r;

    bool operator<(const run& x)const
    {
        return end>x.end;
    }
};

ll n;
ll Max_time=0;
int cnt=0;

set<pll> mem;               // 当前所有空闲区间
priority_queue<run> use;    // 当前运行中的进程，按结束时间排序
queue<elem> q;              // 等待队列

// 找首地址最小、长度 >= need 的空闲区间
pll get_mem(ll need)
{
    for(auto it=mem.begin();it!=mem.end();it++)
    {
        ll l=it->first;
        ll r=it->second;

        if(r-l+1>=need)
        {
            mem.erase(it);

            // 左边 need 个分配出去
            // 剩余部分重新放回空闲区间
            if(l+need<=r)
            {
                mem.insert({l+need,r});
            }

            return {l,l+need-1};
        }
    }

    return {-1,-1};
}

// 释放 [l,r]，并和左右空闲区间合并
void free_mem(ll l,ll r)
{
    auto it=mem.lower_bound({l,LLONG_MIN});

    // 合并左边
    if(it!=mem.begin())
    {
        auto pre=prev(it);

        if(pre->second+1==l)
        {
            l=pre->first;
            mem.erase(pre);
        }
    }

    // 合并右边
    it=mem.lower_bound({l,LLONG_MIN});

    if(it!=mem.end()&&r+1==it->first)
    {
        r=it->second;
        mem.erase(it);
    }

    mem.insert({l,r});
}

// 尝试让 x 在 now 时刻开始运行
bool work_in(elem x,ll now)
{
    pll pos=get_mem(x.m);

    if(pos.first==-1)
    {
        return false;
    }

    ll ed=now+x.p;

    use.push({ed,pos.first,pos.second});

    Max_time=max(Max_time,ed);

    return true;
}

// 处理 now 时刻的结束事件
void work_out(ll now)
{
    // 1. 同一时刻结束的全部先释放
    while(!use.empty()&&use.top().end==now)
    {
        auto x=use.top();
        use.pop();

        free_mem(x.l,x.r);
    }

    // 2. 再处理等待队列
    while(!q.empty())
    {
        elem x=q.front();

        if(work_in(x,now))
        {
            q.pop();
        }
        else
        {
            break;
        }
    }

    // 防止 P=0 时刚进去又在 now 结束
    if(!use.empty()&&use.top().end==now)
    {
        work_out(now);
    }
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

    cin>>n;

    // 最开始 [0,n-1] 全空闲
    mem.insert({0,n-1});

    ll t,m,p;

    while(cin>>t>>m>>p&&(t||m||p))
    {
        // 当前申请发生在 t
        // 把 t 之前以及 t 时刻的结束事件全部处理完
        while(!use.empty()&&use.top().end<=t)
        {
            ll now=use.top().end;
            work_out(now);
        }

        elem x={t,m,p};

        // 当前申请尝试直接运行
        if(!work_in(x,t))
        {
            q.push(x);
            cnt++;
        }
    }

    // 输入结束，但系统里可能还有运行/等待进程
    while(!use.empty())
    {
        ll now=use.top().end;
        work_out(now);
    }

    cout<<Max_time<<endl;
    cout<<cnt<<endl;

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
struct elem
{
ll t,m,p;//初始时间 内存need 时间跨度
};
struct run//正在执行进程
{
ll end;//什么时候用完
ll l,r;//所用的内存块

bool operator<(const run& x)const
{
    return end>x.end;
}
};
ll n;
ll Max_time=0;
int cnt=0;

set<pll> mem;//当前空闲的内存模块
priority_queue<run> use;///正在执行的模块
queue<elem> q;//等待区间内的模块

pll get_mem(ll need)
{
    for(auto it=mem.begin();it!=mem.end();it++)
    {
        ll l=it->first;
        ll r=it->right;

        if(r-l+1>=need)
        {
          mem.erase(it);

          if(l+need<=r)
          {
            mem.insert(l+need,r);
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

    it(it!=mem.end()&&r+1==it->first)
    {
        r=it->right;
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

    ll ed=now+x.p;
    use.push({ed,pos.first,pos.second});
    Max_time=max(Max_time,ed);
    
    return true;
}

void work_out(ll now)
{
    while(!use.empty()&&use.top().end==now)
    {
        auto x=use.top();

        use.pop();

        free_mem(x.l,x.r);
    }

    while(!q.empty())
    {
        elem x=q.front();

        if(work_in(x,now))
        {
          q.pop();
        }
        else
        {
            break;
        }
    }

    if(!use.empty()&&use.top().end()==now)
    {
        work_out(now);
    }
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n;
mem.insert({0,n-1});
ll t,m,p;
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
        q.push(x);
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