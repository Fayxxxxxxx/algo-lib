//这题拓展了一下杨辉三角的求发 对于任意一个这样的上下排列方式
//其最终的total值一定为
for(int i=0;i<n;i++)
{
    C(n-1,i)*(i+1)//这样去求
}

//而12!是小于int的最大阶乘 20!是小于long long的最大阶乘
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
using vc=vector<char>;
using vb=vector<bool>;
const int INF=0x3f3f3f3f;
const int N=13;
int p[N];
int n,total;
vi path;
int C(int a,int b)
{
    return p[a]/(p[b]*p[a-b]);
}//求杨辉三角
bool flag=false;
void dfs(int u,int sum,int s)//现在是求第几个 总和是多少了
{
 if(flag)return;
 if(sum>total)return ;
    
    if(u==n)
    {
      if(total==sum)
      {
          for(int x:path) cout<<x<<" ";
        cout<<endl;
        flag=true;
      }
        return ;
    }

    for(int i=1;i<=n;i++)
    {
        if((s>>i)&1)continue;
        if(sum+C(n-1,u)*i>total)continue;
        path.push_back(i);
        dfs(u+1,sum+C(n-1,u)*i,s|(1<<i));
        path.pop_back();
    }
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n>>total;
p[0]=1;
for(int i=1;i<=12;i++)
{
    p[i]=p[i-1]*i;
}//求阶乘
    dfs(0,0,0);


    return 0;
}