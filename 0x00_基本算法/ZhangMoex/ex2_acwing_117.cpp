#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int arr[13]={};

signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);

vector<deque<int>> nums(14);

for(int i=1;i<=13;i++)
{
    for(int j=1;j<=4;j++){
        char x;
        cin>>x;

        if(x=='0')
        {
            nums[i].push_back(10);
        }
        else if('0'<x&&x<='9')
        {
            nums[i].push_back(x-'0');
        }
        else
        {
           if(x=='A')
           {
             nums[i].push_back(1);
           }
           else if(x=='J')
           {
            nums[i].push_back(11);
           }
           else if(x=='Q')
           {
            nums[i].push_back(12);
           }
           else nums[i].push_back(13);
        }
    }
}

int cnt=0;

while(cnt!=4)
{
    int p=nums[13].front();
    nums[13].pop_front();

    if(p==13)
    {
        cnt++;
        continue;
    }
    

    nums[p].push_front(-p);
    int s_p=nums[p].back();
    nums[p].pop_back();

    while(s_p!=13)
    {
        int tmp;
        nums[s_p].push_front(-s_p);
        tmp=s_p;
        s_p=nums[s_p].back();
        nums[tmp].pop_back();
    }
    cnt++;
}

for(int i=1;i<=13;i++)
{
    for(int j=0;j<nums[i].size();j++)
    {
      if(nums[i][j]<0)
      {
        arr[-nums[i][j]]++;
      }
    }
}

int ans=0;
for(int i=1;i<=12;i++)
{
ans+=arr[i]/4;
}

cout<<ans<<endl;


    return 0;
}