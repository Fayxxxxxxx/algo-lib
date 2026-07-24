//尤其是对个数和操作次数的理解 pos和neg的应用


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
signed  main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

ll n;
cin>>n;

vector<ll> nums(n+2);

for(int i=1;i<=n;i++)
{
    cin>>nums[i];
}

vector<ll> diff(n+2);

diff[1]=nums[1];

ll pos=0;
ll neg=0;

for(int i=2;i<=n;i++)
{
    diff[i]=nums[i]-nums[i-1];
    
    if(diff[i]>0)
    {
        pos+=diff[i];
    }
    else 
    {
        neg-=diff[i];
    }
}

//最少操作数应该为 min(pos,neg)+abs(pos-neg);
//种类数应该为abs(pos-neg)+1;

cout<<min(pos,neg)+abs(pos-neg)<<endl;
cout<<abs(pos-neg)+1;

    return 0;
}