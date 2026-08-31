#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int N=101;
int n;
int arr[N];
vi path;
bool dfs(int dep,int limit)
{
    if(dep==limit)//比如说现在是第三步 则要求啥 x[3]=x[i]+x[j]
    {
        return arr[dep]==n;
    }
    
    for(int i=dep;i>=1;i--)
    {
        for(int j=dep;j>=1;j--)
        {
            int x=arr[i]+arr[j];
            if(x<=arr[dep]||x>n)continue;
            arr[dep+1]=x;
            path.push_back(arr[i+j]);
            if(dfs(dep+1,limit))return true;
            arr[dep+1]=0;
            path.pop_back();
        }
    }
    return false;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
while(cin>>n&&n)
{
    memset(arr,0,sizeof(arr5));
    arr[1]=1;
    path.push_back(1);
    for(int i=1;i<=n;i++)
    {
      if(dfs(1,i))break;
    }
}



    return 0;
}






#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

const int N=101;

int n;
int arr[N];

bool dfs(int dep,int limit)
{
    if(dep==limit)
        return arr[dep]==n;

    // 剩余每一步都翻倍，仍然不可能达到 n
    if(((ll)arr[dep]<<(limit-dep))<n)
        return false;

    bool used[N]={};

    // 从大的数开始组合，优先靠近 n
    for(int i=dep;i>=1;i--)
    {
        for(int j=i;j>=1;j--)
        {
            int x=arr[i]+arr[j];

            // 必须严格递增
            if(x<=arr[dep])continue;

            // 超过 n 后永远回不来
            if(x>n)continue;

            // 当前层相同的下一状态只搜一次
            if(used[x])continue;

            used[x]=1;

            arr[dep+1]=x;

            if(dfs(dep+1,limit))
                return true;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(cin>>n&&n)
    {
        memset(arr,0,sizeof arr);

        arr[1]=1;

        for(int limit=1;;limit++)
        {
            if(dfs(1,limit))
            {
                for(int i=1;i<=limit;i++)
                    cout<<arr[i]<<" ";

                cout<<endl;
                break;
            }
        }
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int N=101;
int arr[N];
bool dfs(int dep,int limit)//dfs dep limit的意思是 此时我已选了dep个数字 长度限制是limit
{
    if(dep==limit)return arr[dep]==n;//我已经选了dep个数字此时长度恰好等于limit 所以要对最后一位进行判断
    bool used[N]={};

    if((ll(arr[dep])<<(limit-dep))<n)return false;
    for(int i=dep;i>=1;i--)//去计算每个值
    {
       for(int j=i;j>=1;j--)
       {
         int x=arr[i]+arr[j];//算出来下一步选啥
         if(x<=arr[dep])continue;//如果算出来<=上一步的值那肯定不对 
         if(x>n)continue;//如果算出来比n还大那肯定不对
         if(used[x])continue;
         arr[dep+1]=x;
         used[x]=true;//这个数算过了 且失败 就不算了 说明第dep+1位不能选这个x
         if(dfs(dep+1,limit))return true;
         arr[dep+1]=0;
         
       } 
    }
    return false;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n;
while(cin>>n&&n)
{
 memset(arr,0,sizeof(arr));
 arr[1]=1;
 for(int limit=1;limit<=n;limit++)
 {
   if(dfs(1,limit))
   {
    for(int i=1;i<=n;i++)cout<<arr[i]<<" ";
    cout<<endl;
   }
 }
}




    return 0;
}