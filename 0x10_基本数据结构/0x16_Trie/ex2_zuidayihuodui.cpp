//我想要求最大 那么对于0而言最好能找到1 对于1而言最好能得到0 
//也就是对于x而言 最好的到x^1 那么我在字典树里面尽可能的找x^1 并加上答案
//即可 如果找不到那么就去找x

//我刚开始还在想去补全32位的字符串 太愚蠢了 可以直接右移来取 我是傻x
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int N=1e5+5;
const int M=N*31;
int son[M][2];
int idx;
void insert(int x)
{
    int u=0;
    for(int i=30;i>=0;i--)
    {
        int bit=(x>>i)&1;
        if(!son[u][bit])
        {
            son[u][bit]=++idx;
        }
        u=son[u][bit];
    }
}
ll query(int x)
{
    int u=0;
    ll res=0;
    for(int i=30;i>=0;i--)
    {
        int bit=(x>>i)&1;
        if(son[u][bit^1])
        {
            res|=(1<<i);
            u=son[u][bit^1];
        }
        else
        {
            u=son[u][bit];
        }
    }
    return res;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n;
cin>>n;
vll nums(n);
ll ans=0;
for(int i=0;i<n;i++)
{
    cin>>nums[i];
    
    if(i>0)
    {
        ans=max(ans,query(nums[i]));
    }
    insert(nums[i]);
}


cout<<ans<<endl;


    return 0;
}