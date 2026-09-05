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
const int INF=0x3f3f3f3f;
int n;
vi nums;//对于分组类问题而言  stick这题足够经典
int sz;//多少组一共
int cap;//容量是多少
int total;
vb vis;
bool dfs(int u,int now,int much)//现在是第几根 目前长度 目前有多少组了
{
    if(much==sz-1)return true;//如果已经有sz-1组了 那不用说了 肯定可以了 直接return true; 这个技巧很有用 对于 n超过8以后的 最后一行他的分支数会越来越多 
    //如果可以直接砍掉一个那可能能砍掉几百万种可能 所以能直接确定下一个的直接剪掉

    if(now==cap)
    {
        return dfs(0,0,much+1);//从头去找 
    }

    int last=-1;
    for(int i=u;i<n;i++)
    {
        if(vis[i])continue;
        if(nums[i]==last)continue;
        if(now+nums[i]>cap)continue;//放不到一个组里
        vis[i]=true;
        if(dfs(i+1,now+nums[i],much))return true;//如果这个返回值是false 说明这样的是有问题的 所以下面就是对这个的分析 如果满足下面几种可能就可以直接return false了
        vis[i]=false;
        if(now+nums[i]==cap)return false;//如果这样的就说明加上整个都是false的
        if(now==0)return false;//也就是这组必然是放现在最大的 结果放了还是不行说明就是有问题 直接可以return false了
        last=nums[i];//防止重复选一样的 把相同的数字跳过去
    }
    return false;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n;
nums.resize(n);
vis.resize(n);
for(int i=0;i<n;i++)
{
    cin>>nums[i];
    total+=nums[i];
}
sort(nums.begin(),nums.end(),greater<int>());
for(int i=nums[0];i<=total;i++)//从小到大这样找到最小可能长度直接ok 首先是从其中最大的那个找（因为必须塞得下）
{
 if(total%i==0)//i是每个组的长度
 {
   vis.assign(n,false);//用assign赋值 下次再也不用clear了
   cap=i;
   sz=total/i;

   if(dfs(0,0,0)){
    cout<<cap<<endl;
    return 0;
   }
 }
}


    return 0;
}


//洛谷卡常 这个写法可过 相当于把上一步的last进行优化 把每个数进行压缩 因为每段的
//长度不超过50 所以开55的cnt
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

const int INF=0x3f3f3f3f;

int n;
int total;
int cap;          // 每组目标长度
int sz;           // 一共需要拼多少组
int maxlen;       // 当前最长木棍

int cnt[55];      // cnt[x] = 长度为 x 的木棍还有多少根

// now：当前这一组已经拼了多长
// last：下一根最多允许选择多长
// much：已经完整拼好的组数
bool dfs(int now,int last,int much)
{
    // 前 sz-1 组都完成后，剩下木棍总和一定正好组成最后一组
    if(much==sz-1)
        return true;

    // 当前这一组已经拼满，开始下一组
    if(now==cap)
        return dfs(0,maxlen,much+1);

    int rest=cap-now;

    // 下一根：
    // 1. 不能超过剩余容量 rest
    // 2. 不能超过上一根 last
    //    保证一组内部从大到小选，消除排列重复
    for(int len=min(last,rest);len>=1;len--)//这个思想很重要
    {
        if(cnt[len]==0)
            continue;

        cnt[len]--;

        if(dfs(now+len,len,much))
            return true;

        cnt[len]++;

        // 剪枝1：
        // 如果这根刚好把当前组补满，
        // 但后面的分组失败了，
        // 那么没必要换别的方式补这一组
        if(now+len==cap)
            return false;

        // 剪枝2：
        // 当前是新开的一组。
        // 当前尝试的第一根一定是最大的未使用木棍。
        // 如果以它开头都无法完成，
        // 那就没必要换别的木棍开头。
        if(now==0)
            return false;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;

        cnt[x]++;
        total+=x;
        maxlen=max(maxlen,x);
    }

    // cap 至少是最长木棍
    for(cap=maxlen;cap<=total/2;cap++)
    {
        // 必须能整除总长度
        if(total%cap!=0)
            continue;

        sz=total/cap;

        if(dfs(0,maxlen,0))
        {
            cout<<cap<<endl;
            return 0;
        }
    }

    // 如果没有任何真因子方案，
    // 所有木棍拼成一根一定可行
    cout<<total<<endl;

    return 0;
}
