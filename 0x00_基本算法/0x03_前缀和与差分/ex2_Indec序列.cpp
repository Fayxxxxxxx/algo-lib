#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n;
cin>>n;
vll nums(n+1);
for(int i=1;i<=n;i++)cin>>nums[i];
vll diff(n+2);
ll cnt_pos=0;
ll cnt_neg=0;

for(int i=2;i<=n;i++)
{
    diff[i]=nums[i]-nums[i-1];
    if(diff[i]>0)
    {
        cnt_pos+=diff[i];
    }
    else
    {
        cnt_neg-=diff[i];
    }
}
cout<<max(cnt_pos,cnt_neg)<<endl;
cout<<abs(cnt_neg-cnt_pos)+1<<endl;


//分给左右边界 可以分0 1 2 3 .....abs(cnt_neg-cnt_pos)份 所以共abs(cnt_neg,cnt_pos)+1份

    return 0;
}