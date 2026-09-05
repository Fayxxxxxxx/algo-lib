void insertsort(vi nums,int n)
{
    for(int i=1;i<n;i++)
    {
        int key=nums[i];
        int j=i-1;

        while(j>=-&&nums[j]>key)
        {
            nums[j+1]=nums[j];
            j--
        }

        nums[j+1]=key;
    }
}

