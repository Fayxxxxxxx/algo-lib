#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
const int N=1e5+5;

struct nod
{
 int val;
 int prev;
 int next;
 int id;
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

void insert(int p,int val,int id)
{
    int q=++tot;
    node[q].val=val;
    node[q].id=id;

    node[node[p].next].prev=q;
    node[q].next=node[p].next;
    node[q].prev=p;
    node[p].next=q;
}

void remove(int p)
{
    node[node[p].prev].next=node[p].next;
    node[node[p].next].prev=node[p].prev;
}
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);

pair<int,int> a[N];
int n;
cin>>n;
for(int i=1;i<=n;i++)
{
int x;cin>>x;
a[i]={x,i};
}
sort(a+1,a+n+1);
initialize();
for(int i=1;i<=n;i++)
{
    insert(node[tail].prev,a[i].first,a[i].second);
}

int pos[N];//求的是下标对应的节点
for(int q=node[head].next;q!=tail;q=node[q].next)
{
    pos[node[q].id]=q;//其实这里这个地方我刚开始就是想不到
}

int ans[N],p[N];
for(int i=n;i>=1;i--)
{
    int k=pos[i];
    int l=node[k].prev;
    int r=node[k].next;
    
    int best;
    if(l==head)
    {
     best=r;
    }
    else if(r==tail)
    {
        best=l;
    }
    else
    {
        int dl=abs(node[l].val-node[k].val);
        int dr=abs(node[r].val-node[k].val);

        if(dl<dr)
        {
            best=l;
        }
        else if(dl>dr)
        {
            best=r;
        }
        else
        {
           best=(node[l].val<=node[r].val?l:r);
        }
    }
    ans[i]=abs(node[best].val-node[k].val);
    p[i]=node[best].id;

    remove(k);
}

for(int i=2;i<=n;i++)cout<<ans[i]<<" "<<p[i]<<endl;

    return 0;
}


//上面是结构体写法 下面是set的写法

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'


signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);
set<int> st;
map<int,int> mp;

int n;
cin>>n;

for(int i=1;i<=n;i++)
{
    int x;cin>>x;
    int diff=LLONG_MAX;
    int best_val;
    int best_pos;
    auto it=st.lower_bound(x);
    if(it!=st.end())
    {
        int d=abs(x-*it);
     if(d<diff)
     {
        best_val=d;
        best_pos=mp[*it];
        diff=d;
     }
    }

    if(it!=st.begin())
    {
        it--;
        int d=abs(x-*it);
      
        if(d<=diff)
        {
            best_val=d;
            best_pos=mp[*it];
        }
    }
    st.insert(x);
    mp.insert({x,i});

    if(i>1)
    {
        cout<<best_val<<" "<<best_pos<<endl;
    }
}



    return 0;
}