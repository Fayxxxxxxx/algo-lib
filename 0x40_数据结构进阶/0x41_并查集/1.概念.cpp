//并查集的职责:
//维护很多个集合,支持“把两个集合合并"和”判断两个元素是否在同一个集合里"
const int N=1e5;

int fa[N];

void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
}
int find(int x)
{
    if(fa[x]==x)return x;//每一个集合都有一个代表 此代表代表了整个集合
    //所以就是去找那个代表
    return fa[x]=find(fa[x]);//路径压缩
    //从5->4->3->2->1
    ->
    //5->1
    //4->1
    //3->1
    //2->1
    //1->1 路径压缩这样更快
}
void merge(int a,int b)
{
    a=find(a);
    b=find(b);

    if(a!=b)
    {
        fa[b]=a;//把b挂在a下
    }
}

