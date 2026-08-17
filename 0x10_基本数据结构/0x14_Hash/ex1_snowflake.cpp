#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int N=100005;
int mod;
vector<bool> is_primes(N,true);
vector<int> primes(N);
int n;
void init()
{
    if(n>=1)is_primes[0]=false;
    if(n>=2)is_primes[1]=false;
    
    int cnt=0;
    for(int i=2;i<=n;i++)
    {
        if(is_primes[i])
        {
            primes[cnt++]=i;
        }
        
        for(int j=0;j<cnt;j++)
        {
            int x=primes[j]*i;
            
            if(x>n)
            {
                break;
            }
            
            is_primes[x]=false;
            
            if(i%primes[j]==0)
            {
                break;
            }
        }
    }
}

int find()
{
   for(int i=n;i>=2;i--)
   {
       if(is_primes[i])
       {
           return i;
       }
   }
}
int head[N];
int snow[N][6];
int nex[N];
int idx;
int H(vector<int>& a)
{
    int s1=0;
    int s2=1;
    
    for(int x:a)
    {
        s1=(s1%mod+x%mod)%mod;
    }
    
    for(int x:a)
    {
        s2=(s2%mod*x%mod)%mod;
    }
    
    return (s1%mod+s2%mod)%mod;
}

void insert(vector<int>& a)
{
    int k=H(a);
    
    for(int i=0;i<6;i++)
    {
        snow[idx][i]=a[i];
    }
    nex[idx]=head[k];
    head[k]=idx;
    
    idx++;
}
bool check(int i,vector<int>&a)
{
  
        for(int k=0;k<6;k++)
        {
            bool same=true;
            
            for(int l=0;l<6;l++)
            {
                if(a[l]!=snow[i][(k+l)%6])//这里只需要对其a[0]即可 所以不需要再嵌套一层循环 书里面多套了一层
                {
                    same=false;
                }
            }
            if(same)
            {
                return true;
            }
            same=true;
            
            for(int l=0;l<6;l++)
            {
                if(a[l]!=snow[i][(k-l+6)%6])
                {
                    same=false;
                }
            }
            if(same)
            {
                return true;
            }
        }
    return false;
}
bool find(vector<int>& a)
{
    int k=H(a);
    
    for(int i=head[k];i!=-1;i=nex[i])
    {
        if(check(i,a))
        {
            return true;
        }
    }
    return false;
}
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n;

if(n==1)
{
    cout<<"No two snowflakes are alike."<<endl;
    return 0;
}
init();
mod=find();
memset(head,-1,sizeof(head));
vector<vector<int>> nums(n,vector<int>(6));

for(int i=0;i<n;i++)
{
    for(int j=0;j<6;j++)
    {
        cin>>nums[i][j];
    }
}

for(int i=0;i<n;i++)
{
    if(find(nums[i]))
    {
        cout<<"Twin snowflakes found."<<endl;
        return 0;
    }
    insert(nums[i]);
}
cout<<"No two snowflakes are alike."<<endl;
    return 0;
}