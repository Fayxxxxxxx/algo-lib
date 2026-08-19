
//小根堆的操作 最上面的是最小的
void up(int u)
{
    while(u>1&&heap[u]<heap[u/2])
    {
        swap(heap[u],heap[u/2]);
        u/=2;
    }
}
//插入 然后向上up 
heap[++sz]=x;
up(sz);

//如果最小值被删除了 之后 接下来就要找一个根节点
//在操作中 我们选最后一个数组元素为根节点
heap[1]=heap[sz];
sz--;

//然后进行down 操作 因为这个节点一定不满足最小
//所以要和他的子节点进行比较 然后进行下放
void down(int u)
{
    int t=u;
    if(u*2<=sz&&heap[u*2]<heap[t])//和左儿子进行比较
    {
        t=u*2;
    }

    if(u*2+1<=sz&&heap[u*2+1]<heap[t])
    {
        t=u*2+1;
    }
    if(t!=u)
    {
        swap(heap[t],heap[u]);
        down(t);//继续下放 直到放到合适的位置
    }
}



//接下来是大根堆 大根堆要求第一个位置一定是最大的
//假设我现在插入了一个元素
heap[++sz]=x;
up(sz);

void up(int u)
{
    while(u>1&&heap[u/2]<heap[u])
    {
        swap(heap[u/2],heap[u]);
        u/=2;
    }
}

//然后就是删除了最大值后的down操作
heap[sz]=heap[1];
sz--;

void down(int u)
{
    int t=u;
    if(u*2<=sz&&heap[u*2]>heap[t])
    {
        t=2*u;
    }

    if(u*2+1<=sz&&heap[u*2]>heap[t])
    {
      t=2*u+1;
    }
    
    if(t!=u)
    {
    swap(heap[t],heap[u]);
    down(t);
    }
}