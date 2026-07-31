#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
int c,n;
int arr[505][505];
int prefix[505][505];

vector<int> xs,ys;

int get_x(int num)
{
    return lower_bound(xs.begin(),xs.end(),num)-xs.begin();
}
int get_y(int num)
{
    return lower_bound(ys.begin(),ys.end(),num)-ys.begin();
}
bool check(int len)
{
   for(int i=0;i<xs.size();i++)
   {
    int j=i;
    while(j<xs.size()&&xs[j]<=xs[i]+len-1)j++;
    j--;

    for(int m=0;m<ys.size();m++)
    {
        int k=m;
        while(k<ys.size()&&ys[k]<=ys[m]+len-1)k++;
        k--;

        int cnt=prefix[j+1][k+1]-prefix[i][k+1]-prefix[j+1][m]+prefix[i][m];

        if(cnt>=c)
        {
            return true;
        }
    }
   }
   return false;
}
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>c>>n;
vector<pair<int,int>> nums(n);
for(int i=0;i<n;i++)
{
    cin>>nums[i].first>>nums[i].second;
    xs.push_back(nums[i].first);
    ys.push_back(nums[i].second);
}
sort(xs.begin(),xs.end());
sort(ys.begin(),ys.end());
xs.erase(unique(xs.begin(),xs.end()),xs.end());
ys.erase(unique(ys.begin(),ys.end()),ys.end());

for(int i=0;i<n;i++)
{
    int x_id=get_x(nums[i].first);
    int y_id=get_y(nums[i].second);

    arr[x_id][y_id]++;
}

for(int i=1;i<=xs.size();i++)
{
    for(int j=1;j<=ys.size();j++)
    {
        prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+arr[i-1][j-1];
    }
}
int left=0;
int right=10001;

while(right-left>1)
{
    int mid=left+(right-left)/2;

    check(mid)?right=mid:left=mid;
}
cout<<right<<endl;
    return 0;
}