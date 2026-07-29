void quick_sort(vector<int>& nums,int left,int right)
{
    if(left>=right)return;
    int pivot=nums[left+(right-left)/2];

    int i=left-1;
    int j=right+1;

    while(i<j)
    {
        do i++;while(a[i]<pivot);
        do j--;while(a[j]>pivot);

        if(i<j) swap(a[i],a[j]);
    }

    quick_sort(nums,left,j);
    quick_sort(nums,j+1,right);

}


//求第k小个

int quick_sort(vector<int>& nums,int l,int r,int k)
{
    if(i==r)
    {
        return nums[i];
    }

    int pivot=nums[left+(right-left)/2];

    int i=l-1;
    int j=r+1;

    while(i<j)
    {
      do i++;while(nums[i]<pivot);
      do j--;while(nums[j]>pivot);

      swap(nums[i],nums[j]);
    }

    int len=j-i+1;

    if(k<=len)
    {
        return quick_sort(nums,l,r,k);
    }
    else
    {
        return quick_sort(nums,j+1,r,k-len);
    }
}





//求第K大的数  降序 只需要改一下nums[i] nums[j] 和pivot比较的符号 让大的数放在左边就好了0

class Solution {
public:
    int quick_sort(vector<int>& nums,int l,int r,int k)
    {
        if(l==r)return nums[l];

        int pivot=nums[l+(r-l)/2];

        int i=l-1;
        int j=r+1;

        while(i<j)
        {
            do i++;while(nums[i]>pivot);
            do j--;while(nums[j]<pivot);

            if(i<j)swap(nums[i],nums[j]);
        }

        int len=j-l+1;

        if(len>=k)
        {
            return quick_sort(nums,l,j,k);
        }
        else
        {
            return quick_sort(nums,j+1,r,k-len);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
    return quick_sort(nums,0,nums.size()-1,k);
    }
};