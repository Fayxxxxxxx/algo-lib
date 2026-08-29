
// 数独 1：推不出来就立刻猜。
// 数独 2：先把所有“不需要猜、已经被约束唯一确定”
// 的格子全部推完，实在推不动了才猜。
//因为多了好多数 数量级上增加了很多
#include<bits/stdc++.h>
using namespace std;

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
using vb=vector<bool>;
string s;
int col[16],row[16],grid[4][4];
const int ALL=(1<<16)-1;

int get_num(int x,int y)    
{
    return row[x]&col[y]&grid[x/4][y/4];
}
void put(int x,int y,int digit)
{
    int t=1<<digit;
    s[x*16+y]='A'+digit;
    row[x]^=t;
    col[y]^=t;
    grid[x/4][y/4]^=t;
}

void remove(int x,int y,int digit)
{
    int t=1<<digit;
    s[x*16+y]='-';
    row[x]^=t;
    col[y]^=t;
    grid[x/4][y/4]^=t;
}
void restore(
    const string &backup_s,
    int backup_row[],
    int backup_col[],
    int backup_grid[][4]
)
{
    s=backup_s;

    memcpy(row,backup_row,sizeof row);
    memcpy(col,backup_col,sizeof col);
    memcpy(grid,backup_grid,sizeof grid);
}

bool propagate(int &remaining)
{
    while(true)
    {
        bool changed=false;

        // 1. 某个格子只有一个候选
        for(int i=0;i<16;i++)
        {
            for(int j=0;j<16;j++)
            {
                if(s[i*16+j]!='-')continue;

                int state=get_num(i,j);

                // 这个空格无任何候选
                if(state==0)return false;

                if(__builtin_popcount(state)==1)
                {
                    int digit=__builtin_ctz(state);

                    put(i,j,digit);

                    remaining--;
                    changed=true;
                }
            }
        }

        // 2. 行：某个字符只剩一个位置
        for(int i=0;i<16;i++)
        {
            for(int d=0;d<16;d++)
            {
                int bit=1<<d;

                // d 已经在该行出现
                if(!(row[i]&bit))continue;

                int cnt=0;
                int pos=-1;

                for(int j=0;j<16;j++)
                {
                    if(s[i*16+j]!='-')continue;

                    if(get_num(i,j)&bit)
                    {
                        cnt++;
                        pos=j;
                    }
                }

                // 这个字符必须出现，但无处可放
                if(cnt==0)return false;

                if(cnt==1)
                {
                    put(i,pos,d);
                    remaining--;
                    changed=true;
                }
            }
        }

        // 3. 列：某个字符只剩一个位置
        for(int j=0;j<16;j++)
        {
            for(int d=0;d<16;d++)
            {
                int bit=1<<d;

                if(!(col[j]&bit))continue;

                int cnt=0;
                int pos=-1;

                for(int i=0;i<16;i++)
                {
                    if(s[i*16+j]!='-')continue;

                    if(get_num(i,j)&bit)
                    {
                        cnt++;
                        pos=i;
                    }
                }

                if(cnt==0)return false;

                if(cnt==1)
                {
                    put(pos,j,d);
                    remaining--;
                    changed=true;
                }
            }
        }

        // 4. 宫：某个字符只剩一个位置
        for(int bi=0;bi<4;bi++)
        {
            for(int bj=0;bj<4;bj++)
            {
                for(int d=0;d<16;d++)
                {
                    int bit=1<<d;

                    if(!(grid[bi][bj]&bit))continue;

                    int cnt=0;
                    int px=-1,py=-1;

                    for(int dx=0;dx<4;dx++)
                    {
                        for(int dy=0;dy<4;dy++)
                        {
                            int x=bi*4+dx;
                            int y=bj*4+dy;

                            if(s[x*16+y]!='-')continue;

                            if(get_num(x,y)&bit)
                            {
                                cnt++;
                                px=x;
                                py=y;
                            }
                        }
                    }

                    if(cnt==0)return false;

                    if(cnt==1)
                    {
                        put(px,py,d);
                        remaining--;
                        changed=true;
                    }
                }
            }
        }

        // 这一轮没有任何新确定值
        if(!changed)
            break;
    }

    return true;
}

bool dfs(int cnt)
{
    if(cnt==0)return true;

    int minv=17;
    int x=-1;
    int y=-1;

   for(int i=0;i<16;i++)
   {
    for(int j=0;j<16;j++)
    {
        if(s[i*16+j]!='-')
        {
            continue;
        }

        int num=get_num(i,j);

        if(num==0)return false;//还没全部填完结果
        //结果这一块没法填了 这不闹嘛
        int c=__builtin_popcount(num);

        if(c<minv)
        {
            minv=c;
            x=i;
            y=j;
        }
    }
   }

   int state=get_num(x,y);
   while(state)
   {
    int t=state&-state;
    int digit=__builtin_ctz(t);
    
    put(x,y,digit);
    
    if(dfs(cnt-1))return true;

    remove(x,y,digit);
    state-=t;

   }
   return false;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
char x;
for(int i=0;i<16*16;i++)
{
    cin>>x;
    s+=x;
}
   for(int i=0;i<16;i++)
   {
    col[i]=ALL;
    row[i]=ALL;
   }
   for(int i=0;i<4;i++)
   {
    for(int j=0;j<4;j++)grid[i][j]=ALL;
   }

   int cnt=0;
   for(int i=0;i<16*16;i++)
   {
    if(s[i]=='-')
    {
        cnt++;
        continue;
    }

    int x=i/16;
    int y=i%16;
    int digit=s[i]-'A';
    int t=1<<digit;
    row[x]^=t;
    col[y]^=t;
    grid[x/4][y/4]^=t;
   }
   dfs(cnt);
   for(int i=0;i<16;i++)
   {
       for(int j=0;j<16;j++)
       {
           cout<<s[i*16+j];
       }
       cout<<endl;
   }


}










#include<bits/stdc++.h>
using namespace std;

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
using vb=vector<bool>;

string s;

int col[16],row[16],grid[4][4];

const int ALL=(1<<16)-1;

int get_num(int x,int y)
{
    return row[x]&col[y]&grid[x/4][y/4];
}

void put(int x,int y,int digit)
{
    int t=1<<digit;

    s[x*16+y]='A'+digit;

    row[x]^=t;
    col[y]^=t;
    grid[x/4][y/4]^=t;
}

void remove_num(int x,int y,int digit)
{
    int t=1<<digit;

    row[x]^=t;
    col[y]^=t;
    grid[x/4][y/4]^=t;

    s[x*16+y]='-';
}

bool propagate(int &remaining)
{
    while(true)
    {
        bool changed=false;

        // 1. 某个格子只有一个候选
        for(int i=0;i<16;i++)
        {
            for(int j=0;j<16;j++)
            {
                if(s[i*16+j]!='-')continue;

                int state=get_num(i,j);

                // 当前空格没有任何合法字符
                if(state==0)return false;

                if(__builtin_popcount(state)==1)
                {
                    int digit=__builtin_ctz(state);

                    put(i,j,digit);

                    remaining--;
                    changed=true;
                }
            }
        }

        // 2. 某一行中，某字符只有一个位置可以放
        for(int i=0;i<16;i++)
        {
            for(int d=0;d<16;d++)
            {
                int bit=1<<d;

                // 该字符已经在这一行出现
                if(!(row[i]&bit))continue;

                int cnt=0;
                int pos=-1;

                for(int j=0;j<16;j++)
                {
                    if(s[i*16+j]!='-')continue;

                    if(get_num(i,j)&bit)
                    {
                        cnt++;
                        pos=j;
                    }
                }

                // 该字符还没出现，却已经没有位置可放
                if(cnt==0)return false;

                if(cnt==1)
                {
                    put(i,pos,d);

                    remaining--;
                    changed=true;
                }
            }
        }

        // 3. 某一列中，某字符只有一个位置可以放
        for(int j=0;j<16;j++)
        {
            for(int d=0;d<16;d++)
            {
                int bit=1<<d;

                if(!(col[j]&bit))continue;

                int cnt=0;
                int pos=-1;

                for(int i=0;i<16;i++)
                {
                    if(s[i*16+j]!='-')continue;

                    if(get_num(i,j)&bit)
                    {
                        cnt++;
                        pos=i;
                    }
                }

                if(cnt==0)return false;

                if(cnt==1)
                {
                    put(pos,j,d);

                    remaining--;
                    changed=true;
                }
            }
        }

        // 4. 某个4x4宫中，某字符只有一个位置可以放
        for(int bi=0;bi<4;bi++)
        {
            for(int bj=0;bj<4;bj++)
            {
                for(int d=0;d<16;d++)
                {
                    int bit=1<<d;

                    if(!(grid[bi][bj]&bit))continue;

                    int cnt=0;
                    int px=-1,py=-1;

                    for(int dx=0;dx<4;dx++)
                    {
                        for(int dy=0;dy<4;dy++)
                        {
                            int x=bi*4+dx;
                            int y=bj*4+dy;

                            if(s[x*16+y]!='-')continue;

                            if(get_num(x,y)&bit)
                            {
                                cnt++;
                                px=x;
                                py=y;
                            }
                        }
                    }

                    if(cnt==0)return false;

                    if(cnt==1)
                    {
                        put(px,py,d);

                        remaining--;
                        changed=true;
                    }
                }
            }
        }

        // 当前局面已经再也推不出确定值
        if(!changed)
            break;
    }

    return true;
}

bool dfs(int cnt)
{
    // 保存进入这一层之前的局面
    string backup_s=s;

    int backup_row[16];
    int backup_col[16];
    int backup_grid[4][4];

    memcpy(backup_row,row,sizeof row);
    memcpy(backup_col,col,sizeof col);
    memcpy(backup_grid,grid,sizeof grid);

    // 先把所有确定性结论推出来
    if(!propagate(cnt))
    {
        s=backup_s;

        memcpy(row,backup_row,sizeof row);
        memcpy(col,backup_col,sizeof col);
        memcpy(grid,backup_grid,sizeof grid);

        return false;
    }

    // 已经全部填完
    if(cnt==0)
        return true;

    // 找候选最少的格子
    int minv=17;
    int x=-1,y=-1;

    for(int i=0;i<16;i++)
    {
        for(int j=0;j<16;j++)
        {
            if(s[i*16+j]!='-')continue;

            int state=get_num(i,j);

            if(state==0)
            {
                s=backup_s;

                memcpy(row,backup_row,sizeof row);
                memcpy(col,backup_col,sizeof col);
                memcpy(grid,backup_grid,sizeof grid);

                return false;
            }

            int c=__builtin_popcount(state);

            if(c<minv)
            {
                minv=c;
                x=i;
                y=j;
            }
        }
    }

    int state=get_num(x,y);

    // 真正需要猜的地方
    while(state)
    {
        int t=state&-state;
        int digit=__builtin_ctz(t);

        put(x,y,digit);

        if(dfs(cnt-1))
            return true;

        remove_num(x,y,digit);

        state-=t;
    }

    // 所有猜测都失败
    // 恢复当前层传播之前的局面
    s=backup_s;

    memcpy(row,backup_row,sizeof row);
    memcpy(col,backup_col,sizeof col);
    memcpy(grid,backup_grid,sizeof grid);

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    char c;

    for(int i=0;i<16*16;i++)
    {
        cin>>c;
        s+=c;
    }

    // 最开始所有字符全部可用
    for(int i=0;i<16;i++)
    {
        row[i]=ALL;
        col[i]=ALL;
    }

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            grid[i][j]=ALL;
        }
    }

    int cnt=0;

    // 根据原始棋盘删掉已经使用的字符
    for(int i=0;i<16*16;i++)
    {
        if(s[i]=='-')
        {
            cnt++;
            continue;
        }

        int x=i/16;
        int y=i%16;

        int digit=s[i]-'A';
        int t=1<<digit;

        row[x]^=t;
        col[y]^=t;
        grid[x/4][y/4]^=t;
    }

    dfs(cnt);

    for(int i=0;i<16;i++)
    {
        for(int j=0;j<16;j++)
        {
            cout<<s[i*16+j];
        }

        cout<<'\n';
    }

    return 0;
}
