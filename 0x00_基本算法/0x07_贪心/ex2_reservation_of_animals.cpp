#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
struct cow
{
 int left;
 int right;
 int id=1;
};

bool cmp(cow& a,cow& b)
{
    if(a.left!=b.left)
    {
        return a.left<=b.left;
    }

    return a.right<=b.right;
}
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);



int n;
cin>>n;

vector<cow> cows(n);

for(int i=0;i<n;i++)
{
    cin>>cows[i].left>>cows[i].right;
}
sort(cows.begin(),cows.end(),cmp);

int left=cows[0].left;
int right=cows[0].right;
int ans=0;

int cnt=0;

vector<int> nums;

for(int i=0;i<n;i++)
{
   int r_left=cows[i].left;
   int r_right=cows[i].right;

   if(r_left<=right)
   {
     nums.push_back(cnt+cows[i].id);
     cnt++;
     ans=max(cnt,ans);

     left=min(left,r_left);
     right=max(right,r_right);
   }
   else
   {
    cnt=1;
    nums.push_back(cows[i].id);

    left=r_left;
    right=r_right;
   }
}

cout<<ans<<endl;
for(int x:nums)
{
    cout<<x<<endl;
}


    return 0;
}


