#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
int n,m;
const int M=22;
int minv[M];
int mins[M];
int ans=INT_MAX;
void dfs(int k,int less_v,int cur_s,int pre_r,int pre_h)
{
if(less_v<minv[k])//这里有俩剪枝了 但还差一个
{
    return ;
}
if(cur_s+mins[k]>=ans)return ;

if(k==0)
{
    if(less_v==0)ans=min(ans,cur_s);
    return ;
}
//第三个强剪枝 当前还剩这么多less_v 无论怎么搭 都至少
//要产生多少侧面积
if(cur_s+2*less_v/pre_r>=ans)return ;

//先算最大r
int maxr=min(pre_r-1,(int)sqrt(double(less_v-minv[k-1])/k));
for(int r=maxr;r>=k;r--)
{//再固定r后计算最大h
    int maxh=min(pre_h-1,(less_v-minv[k-1])/(r*r));
    for(int h=maxh;h>=k;h--)
    {
        int adds=2*r*h;
        if(k==m)adds+=r*r;
        dfs(k-1,less_v-r*r*h,cur_s+adds,r,h);
    }
}
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n>>m;
minv[0]=0;
for(int i=1;i<=m;i++)
{
    minv[i]=minv[i-1]+i*i*i;
}
if(minv[m]>n)
{
    cout<<0<<endl;
    return 0;
}
mins[0]=0;
for(int i=1;i<=m;i++)
{
    mins[i]=mins[i-1]+2*i*i;
}
dfs(m,n,0,sqrt(n)+1,n+1);

cout<<(ans==INT_MAX?0:ans)<<endl;

    return 0;
}