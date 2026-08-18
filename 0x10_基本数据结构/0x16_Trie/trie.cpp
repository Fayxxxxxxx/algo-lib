#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const ll N=1e6;
int son[N][26];
int cnt[N];//记录多少个以此为结尾的字符串 这样才能判断字符串是否存在于字典树中
ll idx;
// 这里的 0 表示：

// 这条边不存在。

// 注意根节点也是编号 0，所以你可能会问：

// 那 son[u][x]=0 到底是“指向根”还是“不存在”？

// 在 Trie 这种写法里，我们约定：

// 不会让普通边指向根节点 0。

// 所以 0 专门拿来表示“没有这个孩子”。
void insert(string s)
{
int u=0;

for(char x:s)//在这里 字符在边上 不在节点处
{
    if(!son[u][x-'a'])
    {
      son[u][x-'a']=++idx;//走这个字符下一个没节点了 就创造一个节点为++idx
    }
    u=son[u][x-'a'];//走到新的节点
}

cnt[u]++;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);


    return 0;
}


void insert(string s)
{
    int u=0;

    for(char c:s)
    {
        int x=c-'a';

        if(!son[u][x])
            son[u][x]=++idx;

        u=son[u][x];

        pass[u]++;//pass[u] 用来记录多少个字符串以此为前缀
    }

    cnt[u]++;
}