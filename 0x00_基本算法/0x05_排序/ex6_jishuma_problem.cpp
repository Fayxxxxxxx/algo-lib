#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
int tmp[N]={};
int ans=0;

void merge_sort(vector<int>& nums,int left,int right){
    if(right-left<=1){
        return ;
    }
    
    int mid=left+(right-left)/2;
    
    merge_sort(nums,left,mid);
    merge_sort(nums,mid,right);
    
    int k=0;
    
    int i=left;
    int j=mid;
    
    while(i<mid&&j<right)
    {
        if(nums[i]<=nums[j])tmp[k++]=nums[i++];
        else
        {
            tmp[k++]=nums[j++];
            ans+=i-mid;
        }
    }
    
    while(i<mid)tmp[k++]=nums[i++];
    while(j<right)tmp[k++]=nums[j++];
    
    
    for(int p=0;p<k;p++)
    {
        nums[left+p]=tmp[p];
    }
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    while(cin>>n)
    {
        
    vector<int> nums1;
    vector<int> nums2;
    
    for(int i=0;i<n*n;i++)
    {
        int x;
        cin>>x;
        
        if(x)
        {
            nums1.push_back(x);
        }
    }
    
    for(int i=0;i<n*n;i++)
    {
        int x;
        cin>>x;
        
        if(x)
        {
            nums2.push_back(x);
        }
    }
    
    if(n==1)
    {
        cout<<"TAK"<<endl;
        continue;
    }
    merge_sort(nums1,0,nums1.size());
    int ans1=ans;
    ans=0;
    memset(tmp,0,sizeof(tmp));
    merge_sort(nums2,0,nums2.size());
    
    cout<<((ans1&1)==(ans&1)?"TAK":"NIE")<<endl;
    ans=0;
    }
    
    
    
    
    return 0;
}