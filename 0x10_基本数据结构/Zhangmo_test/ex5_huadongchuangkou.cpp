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
int n,k;
cin>>n>>k;
vi nums(n);
for(int i=0;i<n;i++)cin>>nums[i];
unordered_map<int,int> mp;
priority_queue<int> Max;
priority_queue<int,vi,greater<int>> Min;
vector<int> v_Max;
vector<int> v_Min;
for(int r=0;r<n;r++)
{
    int l=r-k+1;
    mp[nums[r]]++;
    Max.push(nums[r]);
    Min.push(nums[r]);

    if(l<0)continue;
    
    while(!mp[Max.top()])
    {
        Max.pop();
    }
    while(!mp[Min.top()])
    {
        Min.pop();
    }
    v_Max.push_back(Max.top());
    v_Min.push_back(Min.top());

    mp[nums[l]]--;
    if(mp[nums[l]]==0)
    {
        mp.erase(nums[l]);
    }
}
for(int x:v_Min)cout<<x<<" ";
cout<<endl;
for(int x:v_Max)cout<<x<<" ";
cout<<endl;



    return 0;
}