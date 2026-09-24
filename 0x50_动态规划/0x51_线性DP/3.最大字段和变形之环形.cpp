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
using i128=__int128_t;
const int INF=0x3f3f3f3f;
const int N=2e5+5;
int n;
int f1[N];
int f2[N];

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n;
vi nums(n);
for(int i=1;i<=n;i++)
{
    cin>>nums[i];
}
bool flag=false;
f1[1]=nums[1];
for(int i=1;i<=n;i++)
{
    f1[i]=max(nums[i],f1[i-1]+nums[i]);
    if(f1[i]>=0)
    {
        flag=true;
    }
}
if(!flag)
{
    cout<<*max_element(nums.begin(),nums.end())<<endl;
    return 0;
}
for(int i=1;i<=n;i++)
{
    f2[i]=min(nums[i],f2[i-1]+nums[i]);
}
//1.如果没有越过最后 那么其就是最普通的最大自序和
//2.但是如果越过了 那么就是后面取一段加上前面取一段 那么相当于全部的减去中间的部分
//想要其最大那么就是让中间的部分最小 那么就是最小字段和的问题 

//但是如果全是负数 那么最小字段和也就是负数 那么其值就是0 了 怎么可能为0 所以此时答案就是其中
//的最大值 所以要特判
int total=accumulate(nums.begin(),nums.end(),0);

int Max=INT_MIN;

for(int i=1;i<=n;i++)
{
    Max=max({Max,f1[i],total-f2[i]});
}
cout<<Max<<endl;



    return 0;
}