复制 a
↓
排序 + 去重
↓
每个 a[i] 找 rank
↓
BIT 中维护 rank 出现次数
↓
query 统计需要的大小关系
↓
add(rank, 1)
vll a(n);
vll nums(n);
for(int i=0;i<n;i++)
{
    cin>>a[i];
    nums[i]=a[i];
}
sort(nums.begin(),nums.end());
nums.erase(unique(nums.begin(),nums.end()),nums.end());
int get(int x)
{
    return (int)(lower_bound(nums.begin(),nums.end(),x)-nums.begin())+1;
}
int query(int x)
{
    int res=0;
    while(x)
    {
      res+=tr[x];
      x-=x&-x;
    }
    return res;
}
int m=nums.size();//树状数组就是这样 对点增加 求前缀和要把
//所有包含这个点的区域都+=k 所以就是add(pos)
void add(int pos)
{
    while(pos<=m)
    {
        tr[pos]+=1;
        pos+=pos&-pos;
    }
}

int cal()
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int x=a[i];

        int pos=get(x);

        ans+=i-query(pos);
        add(pos);
    }
    return ans;
}