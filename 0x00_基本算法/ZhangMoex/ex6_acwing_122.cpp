//就是环形均分

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int n;
const int N=1e6+10;
int arr[N];
int prefix[N];
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);

cin>>n;
int avg=0;
for(int i=1;i<=n;i++)
{
    cin>>arr[i];
    avg+=arr[i];
}
avg/=n;

for(int i=1;i<=n;i++)
{
    prefix[i]=prefix[i-1]+arr[i]-avg;
}
sort(prefix+1,prefix+n+1);

int ans=0;

for(int i=1;i<=n;i++)
{
    ans+=abs(prefix[i]-prefix[n/2+1]);
}
cout<<ans<<endl;

    return 0;
}