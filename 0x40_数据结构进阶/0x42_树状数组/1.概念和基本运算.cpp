//1.tr[x]表示[x-lowbit(x)+1,x]这一区域内之和
//长度为lowbit(x)

//所以我想询问1~x的前缀和 那么就可以写为
int query(int x)
{
    int ans=0;

    while(x)
    {
        ans+=tr[x];
        x-=x&-x;
    }
    return ans;
}

//假设我修改了某一个值 比如a[3]+=5 那么如果是一般的
//数组 我前缀和等等等等修改都要加5 那么一定是O(n)的
//而树状数组研发出来可以使得复杂度压缩到O(logn)

假设a[3]+=5;
那些tr[]会受到影响？

首先tr[3]
然后tr[4] 负责[1,4] 也包含a[3]

然后tr[8] 负责[1,8] 也包含a[3]

所以3->4->8 刚好是加lowbit(3)
void add(int x,int k)
{
    while(x<=n)
    {
        tr[x]+=k;
        x+=x&-x;
    }
}
求一个区间内的前缀和比如l和r
那就是 query(r)-query(l-1)


//而构造就把每一个值一个点都当一次单点修改 加进去

for(int i=1;i<=n;i++)//写树状数组最好就是用1-base 别用0-base
{
    cin>>a[i];
    add(i,a[i]);
}




const int N=1e5;
int tr[N]={};

void add(int x,int k)
{
    while(x<=n)
    {
        tr[x]+=k;
        x+=x&-x;
    }
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

void init()
{
    vi nums(n+1);
    for(i=1;i<=n;i++)
    {
        cin>>nums[i];
        add(i,nums[i]);
    }
}