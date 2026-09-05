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
int cnt=0;
int n;
vi nums;
void dfs(int i)
{
    if(i==n+1)
    {
        if(nums[n]==0) cnt++;//最后一步没有检验pre了所以要特判一下
        return ;
    }

    int pre=nums[i-1];
    
    if(pre==4)
    {
        dfs(i+1);
        //上面是选 下面是不选
    nums[i-1]--;
    nums[i]--;
    nums[i+1]--;
    dfs(i+1);
    nums[i-1]++;
    nums[i]++;
    nums[i+1]++;

    }
    

    
    if(pre<0||pre==2||pre==3)return ;

    if(pre==0)
    {
        dfs(i+1);
        return ;//对于特判的要提前return 防止污染后面
    }
    //那就只剩下pre==1的可能了
    if(pre<0||nums[i]<=0||nums[i+1]<=0)return;
    nums[i-1]--;
    nums[i]--;
    nums[i+1]--;
    dfs(i+1);
    nums[i-1]++;
    nums[i]++;
    nums[i+1]++;

}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n;
nums.resize(n+2);
nums[0]=4;
nums[n+1]=4;
for(int i=1;i<=n;i++)cin>>nums[i];
//取到n即可
dfs(1);

cout<<cnt<<endl;

    return 0;
}