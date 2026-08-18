#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s,p;
    cin>>s>>p;

    int n=s.size();
    int m=p.size();

    s=" "+s;
    p=" "+p;

    vector<int> ne(m+1);

    // 1. 求 next
    for(int i=2,j=0;i<=m;i++)//求next数组就靠跟自己比较 
    {
        while(j && p[i]!=p[j+1])
        {
            j=ne[j];
        }

        if(p[i]==p[j+1])
        {
            j++;
        }

        ne[i]=j;//一次最多增长一个嘛
    }

    // 2. KMP 匹配
    for(int i=1,j=0;i<=n;i++)
    {
        while(j && s[i]!=p[j+1])
        {
            j=ne[j];
        }

        if(s[i]==p[j+1])
        {
            j++;
        }

        if(j==m)
        {
            cout<<i-m+1<<endl;

            j=ne[j];//兜底
        }
    }

    return 0;
}
