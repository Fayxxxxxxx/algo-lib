//于这题而言 还是要好好读题 我曲解题意了 没搞懂真的要连的是什么 以及他刚开始说的以龙为开头的
//这题也学习了一下string的substr写法 substr(就一个数)//则是从这个数到string的末尾
//如果是 substr(一个数,另一个数)则是从前面那个下标开始往后取另一个数个数的字符
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
int ans=0;
vs nums;
vi cnt;

int check(string s1,string s2)
{
    for(int len=1;len<min((int)s1.size(),(int)s2.size());len++)
    {
        if(s1.substr(s1.size()-len)==s2.substr(0,len))
        {
            return len;
        }
    }

    return -1;
}

void dfs(int u,int len)
{
    ans=max(ans,len);

    for(int i=0;i<n;i++)
    {
        if(cnt[i]>=2) continue;
        int overlap=check(nums[u],nums[i]);
        if(overlap==-1) continue;
        cnt[i]++;
        dfs(i,len+(int)nums[i].size()-overlap);
        cnt[i]--;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;

    nums.resize(n);
    cnt.resize(n);

    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }

    char st;
    cin>>st;
    for(int i=0;i<n;i++)
    {
        if(nums[i][0]==st)
        {
            cnt[i]++;
            dfs(i,nums[i].size());
            cnt[i]--;
        }
    }

    cout<<ans<<endl;

    return 0;
}
