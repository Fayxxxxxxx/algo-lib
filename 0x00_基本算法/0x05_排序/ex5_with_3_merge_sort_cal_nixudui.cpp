    #include<bits/stdc++.h>
    using namespace std;

    #define int long long
    const int N=1e6;

    int tmp[N]={};
    int ans=0;

    void merge_sort(vector<int>& nums,int left,int right)
    {
        if(right-left<=1)return;
        
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
                ans+=mid-i;
            }
                
        }
        
        while(i<mid)tmp[k++]=nums[i++];
        while(j<right)tmp[k++]=nums[j++];
        
        for(int p=0;p<k;p++)
        {
            nums[p+left]=tmp[p];//这里一定要记清楚
        }
    }
    signed main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int n;
        
        while(cin>>n&&n!=0)
        {
            vector<int> nums(n);
            ans=0;
            
            for(int i=0;i<n;i++)
            {
                cin>>nums[i];
            }
            merge_sort(nums,0,nums.size());
            
            cout<<ans<<endl;
            
        }
        
        
        return 0;
    }