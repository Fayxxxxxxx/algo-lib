#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
int n;

struct cow
{
    int w,s;
};
bool cmp(cow&a,cow& b)
{
    if(a.w+a.s!=b.w+b.s)
    {
        return a.w+a.s>b.w+b.s;
    }
}
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n;
int sum=0;
vector<cow> cows(n+1);
for(int i=1;i<=n;i++)
{
    cin>>cows[i].w>>cows[i].s;
    sum+=cows[i].w;
}
sort(cows.begin()+1,cows.end(),cmp);

vector<int> prefix(n+1);

for(int i=1;i<=n;i++)
{
    prefix[i]=prefix[i-1]+cows[i].w;    
}
int ans=INT_MIN;
for(int i=1;i<=n;i++)
{
ans=max(ans,sum-prefix[i]-cows[i].s);
}
cout<<ans<<endl;


    return 0;
}