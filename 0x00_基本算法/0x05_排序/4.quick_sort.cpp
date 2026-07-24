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