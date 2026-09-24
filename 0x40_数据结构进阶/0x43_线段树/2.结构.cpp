struct node
{
int l,r;
ll sum;
}tr[4*N];



void pushup(int u)
{
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}

void build(int u,int l,int r)
{
    tr[u]={l,r,0};

    if(l==r)
    {
        tr[u].sum=a[l];
        return ;
    }
    
    int mid=(l+r)>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);

    pushup(u);
}

void modify(int u,int x,int k)
{
    if(tr[u].l==tr[u].r)
    {
        tr[u].sum+=k;
        return ;
    }

    int mid=(tr[u].l+tr[u].r)>>1;

    if(mid>=x)  
    {
        modify(u<<1,x,k);
    }
    else
    {
        modify(u<<1|1,x,k);
    }

    pushup(u);  
}

ll query(int u,int l,int r)
{
    if(l<=tr[u].l&&tr[u].r<=r)
    {
        return tr[u].sum;
    }

    int mid=(tr[u].l+tr[u].r)>>1;

    ll res=0;
//如果以后的值里面会出现负数 那么要把res设为LLONG_MIN;
    if(l<=mid)
    {
        res+=query(u<<1,l,r);
    }

    if(r>mid)
    {
        res+=query(u<<1|1,l,r);
    }

    return res;
}