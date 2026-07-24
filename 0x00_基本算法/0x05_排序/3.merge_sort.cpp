const int N=1e5;

int tmp[N];


void merge_sort(vector<int>& nums,int left,int right)
{
if(right-left<=1)
{
    return ;
}

int mid=left+(right-left)/2;

merge_sort(nums,left,mid);//从left到mid 左闭右开
merge_sort(nums,mid,right);

int k=0;

int i=left,j=mid;

while(i<mid&&j<right)
{
    if(nums[i]<=nums[j])
    {
      tmp[k++]=nums[i++];
    }
    else
    {
        tmp[k++]=nums[j++];
        cnt += mid - i ;    // ★ 关键行：左半剩余的 [i..mid] 都 > a[j]
    }
}

while(i<mid)
{
    tmp[k++]=nums[i++];
}
while(j<right)
{
    tmp[k++]=nums[j++];
}

for(int p=0;p<k;p++)
{
    a[left+p]=tmp[p];
}
}