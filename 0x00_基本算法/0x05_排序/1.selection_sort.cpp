void sort(vector<int> nums)//升序   
{
    for(int i=0;i<n-1;i++)
    {
      int k=i;

      for(int j=i+1;j<n;j++)
      {
        if(nums[k]<nums[j])
        {
            k=j;
        }
      }
      swap(nums[k],nums[i]);
    }
}