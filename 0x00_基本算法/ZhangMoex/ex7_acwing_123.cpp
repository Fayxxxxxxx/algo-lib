货舱选址的模型

  ▎ n 个点在直线上，找一个集合点，使总距离最小 → 中位数。

  这你已经掌握了。

  ---
  士兵的 X 跟货舱选址差了什么？

  货舱选址：所有人站同一个点。

  士兵：所有人站相邻——aa+1, a+2, a+3, ...

  怎么把"站一排"变成"站同一点"？

  排好序后，第 i 个兵的最终位置是 a + i。他当前的 x 坐标是 x[i]。

  移动距离 = |x[i] - (a + i)|
           = |(x[i] - i) - a|       ←把 i 移过去

  令 z[i] = x[i] - i。

  移动距离 = |z[i] - a|

  这就变成了：z 数组上找一个 a，使 Σ|z[i]- a| 最小——跟货舱选址一模一样！

  ---
  直觉

  "站成一排"其实就是每个人被自己的序号 i 往后推了 i 格。把"被推的距离"提前扣掉（x[i] -
  i），剩下的就是"如果站同一个点，你的位置"。

  打个比方：你让 5 个人站成一排（间隔 1 米），第一个人不动，第二个人往右挪 1 米，第三个人往右挪 2 米...
  如果把每个人的"额外偏移"提前减掉，就变成了"5 个人全站同一个点"。

  ---
  所以怎么想到的？

  不是凭空想出来的。你做过货舱选址，然后看到这题——第一反应是"坐标好办，中位数"。x
  坐标卡住了，想"能不能把相邻条件消掉"，就尝试把 a+i 拆开，得到 |x[i] - i - a|。

  核心技巧：把目标公式拆开，把变量（a 和 i）分开。 这个套路在竞赛里反复出现——绝对值表达式的变量分离。


//这题是货舱选址的变形题iu
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

vector<int> xs;
vector<int> ys;

int n;
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n;
for(int i=0;i<n;i++)
{
    int x,y;
    cin>>x>>y;
    xs.push_back(x+10000);
    ys.push_back(y+10000);
}
sort(ys.begin(),ys.end());
sort(xs.begin(),xs.end());
int ans=0;

for(int i=0;i<xs.size();i++)
{
    ans+=abs(ys[i]-ys[ys.size()/2]);
}
vector<int> z;

for(int i=0;i<n;i++)
{
    z.push_back(xs[i]-i);
}


sort(z.begin(),z.end());
for(int i=0;i<n;i++)
{
    ans+=abs(z[i]-z[n/2]);
}
cout<<ans<<endl;






    return 0;
}