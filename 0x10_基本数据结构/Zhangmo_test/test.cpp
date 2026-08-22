#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

struct num
{
  int val;
  int id;
};

bool cmp(num&a,num&b)
{
    return a.val<b.val;
}
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n;
cin>>n;
vector<num> nums(n);
for(int i=0;i<n;i++)
{
    cin>>nums[i].val;
    nums[i].id=i+1;
}
sort(nums.begin(),nums.end(),cmp);

bool flag=false;//降序
int ans=1;//刚开始假设有一个
int last=INT_MAX;
for(int i=0;i<n;)
{
    int j=i;
    int maxx=0;
    int minx=INT_MAX;
    
    while(j<n&&nums[j].val==nums[i].val)
    {
        maxx=max(maxx,nums[j].id);
        minx=min(minx,nums[j].id);
        j++;
    }
    
    if(!flag)
    {
        if(maxx<last)
        {
            last=minx;
        }
        else
        {
            flag=true;
            last=maxx;
        }
    }
    else
    {
        if(minx>last)
        {
            last=maxx;
        }
        else
        {
            flag=false;
            ans++;
            last=minx;
        }
    }
    i=j;
}
cout<<ans<<endl;


    return 0;
}