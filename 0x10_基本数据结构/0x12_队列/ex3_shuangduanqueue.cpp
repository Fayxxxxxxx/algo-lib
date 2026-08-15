#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
//单边也算谷 纯上升 纯下降 或者先降后升
struct num
{
 int a;
 int id;
};
bool cmp(num&a, num&b)
{
    return a.a<b.a;
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
    cin>>nums[i].a;
    nums[i].id=i+1;
}
sort(nums.begin(),nums.end(),cmp);

int ans=1;
bool down=true;//true为下降 false为上升

int last=LLONG_MAX;

for(int i=0;i<n;)
{
    int j=i;

    int mn=LLONG_MAX;
    int mx=0;

    while(j<n&&nums[j].a==nums[i].a)
    {
        mn=min(mn,nums[j].id);
        mx=max(mx,nums[j].id);
        j++;
    }
    if(down)
    {
        if(mx<last)
        {
            last=mn;
        }
        else
        {
            down = false;
            last = mx;
        }
    }
    else
    {
        if(mn>last)
        {
            last=mx;
        }
        else
        {
            down = true;
            last = mn;
            ans++;
        }
    }
    i=j;

}
cout<<ans<<endl;

    return 0;
}