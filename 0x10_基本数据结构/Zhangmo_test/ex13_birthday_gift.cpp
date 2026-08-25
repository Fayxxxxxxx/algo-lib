#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

const int N=1e5+10;

ll a[N],b[N];
int l[N],r[N];
bool del[N];

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

    int n,m;
    cin>>n>>m;

    int len=0;

    for(int i=1;i<=n;i++)
    {
        ll x;
        cin>>x;

        if(x==0) continue;

        if(len==0||(x>0)!=(b[len]>0))//可以学习一下 这里是合并同符号数组为一个区间
        {
            b[++len]=x;
        }
        else
        {
            b[len]+=x;
        }
    }

    if(len==0)
    {
        cout<<0<<endl;
        return 0;
    }

    priority_queue<pll,vector<pll>,greater<pll>> q;

    ll ans=0;
    int cnt=0;

    for(int i=1;i<=len;i++)
    {
        a[i]=b[i];

        l[i]=i-1;
        r[i]=i+1;

        q.push({abs(a[i]),i});

        if(a[i]>0)
        {
            ans+=a[i];
            cnt++;
        }
    }

    auto remove=[&](int x)
    {
        if(x<1||x>len) return;

        del[x]=true;

        r[l[x]]=r[x];
        l[r[x]]=l[x];
    };
    while(cnt>m)
    {
        auto [val,id]=q.top();
        q.pop();

        if(del[id]) continue;

        if(a[id]<0&&(l[id]<1||r[id]>len))//如果一个负数区间不满足左右同时存在正数区间 那么就continue
        {
            continue;
        }

        ans-=val;
        cnt--;

        int L=l[id];
        int R=r[id];

        if(L>=1) a[id]+=a[L];
        if(R<=len) a[id]+=a[R];

        remove(L);
        remove(R);

        q.push({abs(a[id]),id});
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
const int N=1e5+10;
ll a[N],b[N];
int l[N],r[N];
vector<bool> del(N,false);
ll ans=0;
int cnt=0;
int n,m;
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n>>m;
int len=0;
for(int i=0;i<n;i++)
{
    ll x;
    cin>>x;

    if(x==0)continue;
    if(len==0||((x>0)!=(b[len]>0)))
    {
       b[++len]=x;
    }
    else
    {
        b[len]+=x;
    }
}
if(len==0)
{
    cout<<0<<endl;
    return 0;
}
priority_queue<pll,vector<pll>,greater<pll>> pq;
for(int i=1;i<=len;i++)
{
    a[i]=b[i];
    l[i]=i-1;
    r[i]=i+1;

    pq.push({abs(a[i]),i});

    if(a[i]>0)
    {
        ans+=a[i];
        cnt++;
    }
}

auto remove=[&](int x)
{
    if(x<1||x>len)
    {
        return ;
    }
  int left=l[x];
  int right=r[x];

  del[x]=true;
  r[left]=right;
  l[right]=left;
};

while(cnt>m)
{
    auto [val,id]=pq.top();
    pq.pop();
    if(del[id])continue;

    if(a[id]<0&&(l[id]==0||r[id]==len+1))continue;

    ans-=val;
    cnt--;
    
    int left=l[id];
    int right=r[id];

    if(left>=1)a[id]+=a[left];
    if(right<=len)a[id]+=a[right];

    remove(left);
    remove(right);
    
    pq.push({abs(a[id]),id});
}
cout<<ans<<endl;



    return 0;
}