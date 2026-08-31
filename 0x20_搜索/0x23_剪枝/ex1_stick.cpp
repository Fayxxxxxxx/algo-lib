//TLE
// #include<bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll=long long;
// using pii=pair<int,int>;
// using pll=pair<ll,ll>;
// using vi=vector<int>;
// using vll=vector<ll>;
// int n;
// vi nums;
// vi group;
// int size;
// int cap;
// bool dfs(int l)
// {
//   if(l==n)
//   {
//      return true;
//   }

//   set<int> st;

//   for(int i=0;i<size;i++)
//   {
//     if(st.count(group[i]))continue;
//     if(nums[l]+group[i]>cap)continue;
//     st.insert(group[i]);

//     group[i]+=nums[l];
//     if(dfs(i+1))return true;
//     group[i]-=nums[l];
//   }
//   return false;
// }
// int main()
// {
// ios::sync_with_stdio(0);
// cin.tie(0);
// while(cin>>n&&n)
// {
//     nums.resize(n);
// for(int i=0;i<n;i++)cin>>nums[i];
// sort(nums.begin(),nums.begin()+n,greater<int>());
// int Max=nums[0];
// int total=accumulate(nums.begin(),nums.begin()+n);
// for(int i=Max;i<=total;i++)
// {
// if(total%i==0)
// {
//     group.clear();
//     group.resize(total/i);//group的大小为total/i 容量为i
//     size=total/i;
//     cap=i;
//     if(dfs(0))
//     {
//         cout<<i<<endl;
//         break;
//     }
// }
// }
// }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
int n;
vi nums;
int groups;
int cap;
vi vis;
bool dfs(int done,int cur,int start)
{
    if(done==groups-1)return true;//因为剩下的一定是cap个 算一组 所以没必要再去检验了 所以done==groups-1就可以了

    if(cur==cap)return dfs(done+1,0,0);//如果成一组了 就dfs下一组
    int last=-1;//和之前的是不是一样的
        for(int i=start;i<n;i++)//防止产生重复
        {
            if(last==nums[i])continue;//选过且失败 跳过
            if(vis[i])continue;//选过了 跳过
            if(cur+nums[i]>cap)continue;//成不到一组 跳过
            vis[i]=1;
            if(dfs(done,cur+nums[i],i+1))return true;
            vis[i]=0;
            last=nums[i];//已经尝试选择这个的可能 并失败 所以下次不用了
            if(cur+nums[i]==cap)return false;//如果已经用了一个封口的还失败了 肯定有问题(这个好难想)
            if(cur==0)return false;//如果尝试了目前的最大都不可以 那么一定无解 也就是我选了最大了 然后去递归递归 结果最后的返回值是false 说明我选了最大还是不行 所以return false
        }
    return false;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
while(cin>>n&&n)
{
    nums.resize(n);
    vis.clear();
    vis.resize(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    sort(nums.begin(),nums.begin()+n,greater<int>());
    int Max=nums[0];
    int total=accumulate(nums.begin(),nums.end(),0);
    for(int i=Max;i<=total;i++)
    {
        if(total%i==0)
        {
            groups=total/i;
            cap=i;
            if(dfs(0,0,0))
            {
                cout<<i<<endl;
                break;
            }
        }
    }
}



    return 0;
}