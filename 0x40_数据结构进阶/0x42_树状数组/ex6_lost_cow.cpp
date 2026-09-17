//刚好用树状数组去维护第k小 用前缀和
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
using vs=vector<string>;

const int N=1e5+5;

int n;
int a[N];
int ans[N];
int tr[N];

void add(int x,int k)
{
    while(x<=n)
    {
        tr[x]+=k;
        x+=x&-x;
    }
}

int query(int x)
{
    int res=0;

    while(x)
    {
        res+=tr[x];
        x-=x&-x;
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;

    a[1]=0;

    for(int i=2;i<=n;i++)
    {
        cin>>a[i];
    }

    // 身高 1~n 一开始全部可用
    for(int i=1;i<=n;i++)
    {
        add(i,1);
    }

    // 倒序还原
    for(int i=n;i>=1;i--)
    {
        // 牛 i 是剩余身高中的第 k 小
        int k=a[i]+1;

        // 找最小 x，使 query(x)>=k
        int l=0,r=n;

        while(r-l>1)
        {
            int mid=l+(r-l)/2;

            query(mid)>=k?r=mid:l=mid;
        }

        ans[i]=r;

        add(r,-1);
    }

    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<endl;
    }

    return 0;
}