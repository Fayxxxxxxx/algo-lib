struct node
{
int val;
int prev;
int next;
}node[N];
int head,tail,tot;
void initialize()
{
    tot=2;
    head=1;
    tail=2;
    node[head].next=tail;
    node[tail].prev=head;
}

void insert(int p,int val)
{
    q=++tot;
    node[q].val=val;
    node[node[p].next].prev=q;
    node[q].next=node[p].next;
    node[p].next=q;
    node[q].prev=p;
}

void remove(int p)
{
    node[node[p].prev].next=node[p].next;
    node[node[p].next].prev=node[p].prev;
}
void clear()
{
    memeset(node,0,sizeof(node));
    head=tail=tot=0;
}