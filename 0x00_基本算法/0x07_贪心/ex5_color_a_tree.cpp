#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int n,r;
struct block
{
 int size;
 int father;
 int value;

 double avg;
};
vector<block> blocks;
int find()
{
    int res=-1;
    double avg=0;
    
    for(int i=1;i<=n;i++)
    {
        if(i != r && avg < blocks[i].avg)
        {
            avg = blocks[i].avg;
            res = i;
        }
    }
    return res;
}
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);
    
    while(cin >> n >> r&& n && r)
    {
int ans = 0;
    blocks.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>blocks[i].value;
        blocks[i].size=1;
        blocks[i].avg=(double)(blocks[i].value);
        ans+=blocks[i].value;
    }

    for(int i=1;i<n;i++)    
    {
        int u,v;
        cin>>u>>v; 
        blocks[v].father=u;
    }

    for(int i=0;i<n-1;i++)
    {
        int p = find();
        int father = blocks[p].father;
        ans += blocks[father].size * blocks[p].value;//尤其是对这里的理解
        blocks[p].avg = -1;
        for(int j = 1; j <= n;j ++)
        {
            if(blocks[j].father == p)
            {
                blocks[j].father = father;
            }
        }
         blocks[father].value += blocks[p].value;
            blocks[father].size += blocks[p].size;
            blocks[father].avg  = (double)blocks[father].value/blocks[father].size;
    }
        
        
    cout<<ans<<endl;
    }
    
    return 0;
}

