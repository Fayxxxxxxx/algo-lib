#include<bits/stdc++.h>
using namespace std;


int lower(vector<int>&nums,int x)
{
int left=0;
int right=nums.size()-1;

while(right-left>1)
{
    int mid=left+(right-left)/2;

    nums[mid]>=x?right=mid:left=mid;
}

return right;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

vector<int> nums={1,2,3,4,5};

cout<<lower(nums,3);


    return 0;
}