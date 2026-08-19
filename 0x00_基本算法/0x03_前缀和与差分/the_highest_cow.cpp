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
int n,p,h,m;
cin>>n>>p>>h>>m;
vi diff(n+2);
map<pii,int> mp;
for(int i=0;i<m;i++)
{
    int x,y;
    cin>>x>>y;
    if(x>y)
    {
        swap(x,y);
    }
    if(mp[pii(x,y)])
    {
        continue;
    }
    else
    {
        mp[pii(x,y)]++;
    }
    diff[x+1]--;
    diff[y]++;
}
vi nums(n+1);
for(int i=1;i<=n;i++)
{
    nums[i]=nums[i-1]+diff[i];
}
for(int i=1;i<=n;i++)
{
    cout<<nums[i]+h<<endl;
}



    return 0;
}