在一条数轴上有 N
 家商店，它们的坐标分别为 A1∼AN
。

现在需要在数轴上建立一家货仓，每天清晨，从货仓到每家商店都要运送一车商品。

为了提高效率，求把货仓建在何处，可以使得货仓到每家商店的距离之和最小。

输入格式
第一行输入整数 N
。

第二行 N
 个整数 A1∼AN
。

输出格式
输出一个整数，表示距离之和的最小值。

数据范围
1≤N≤100000
,
0≤Ai≤40000

输入样例：
4
6 2 9 1
输出样例：
12

#include<bits/stdc++.h>
using namespace std;

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

int n;
cin>>n;

vector<int> nums;
for(int i=0;i<n;i++)
{
    int x;
    cin>>x;
    
    nums.push_back(x);
}
sort(nums.begin(),nums.end());

int ans=0;

if(n&1)
{
    int half=n/2;
    
    for(int i=1;half-i>=0;i++)
    {
        ans+=nums[half+i]-nums[half-i];
    }
    
}
else
{
    for(int i=0;i<n/2;i++)
    {
        ans+=nums[n-i-1]-nums[i];
    }
}

cout<<ans<<endl;



    return 0;
}