试想一个问题 对[l,r]进行+=k的操作
如果x在此范围内 如何去求a[x]

原本求x的操作是 tr[x]-tr[x-1] 因为树状数组最擅长就是维护前缀和 和单点修改
 
单点修改只需要使用add函数 并且是log(n)的 

基于此性质 我如果想要大量重复的对[l,r]进行+=k的操作 并且要求a[x]

不妨不要维护原数组a 而是先求出其差分数组 然后按照构建树状数组的方法 用差分数组进行构建树状数组 

然后对[l,r]+=k 等价于 diff[l]+=k diff[r+1]-=k
所以单点操作 add(l,k) add(r+1,-k)即可
然后如果要求 a[x] 那么就是求差分数组的前缀和 也就是query(x)

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
vi a(n+1);

for(int i=1;i<=n;i++)cin>>a[i];

for(int i=1;i<=n;i++)
{
    add(i,a[i]-a[i-1]);
}

比如对[l,r]进行+=k的操作
int l,r;
cin>>l>>r;
int k;
cin>>k;

add(l,k);
add(r+1,-k);

然后要求a[x]

cout<<query(x);






2.如果给一段[l,r]+=k 后求a[l]+a[l+1]+.....+a[r]?
此时我们要维护两个树状数组
推到有
bi=ai-ai-1;
ai=b1+b2+b3+......bi;
sumi=a1+a2+a3+a4......+ai;

sumi=b1+(b1+b2)+(b1+b2+b3)+......(b1+b2+b3+.....bi);

sumi=∑x​(i)(x-i+1)===(x+1)∑x​(i)bi-∑x​(i) i*bi

所以需要一个树状数组维护bi 一个维护i*bi


所以sum(x)=(x+1)*∑x​(i)(bi)-∑x​(i)i*bi
=(x+1)*query(tr1,x)-query(tr2,x)

第一棵树
add(l,k)
add(r+1,-k)

第二棵树
add(l,k*l)
add(r+1,-k*(r+1))

最后求a[l]+.....+a[r]==sum(r)-sum(l-1)

ll tr1[N],tr2[N];
