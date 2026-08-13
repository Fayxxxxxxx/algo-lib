//类似动态中位数的思想 利用两个堆来进行切割分配 
//主要还是没想到对于sum和f就不需要理会倒退 直接进行覆盖就可以了

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int N=1e6;

signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);

stack<int> A;
stack<int> B;
vector<int> sum(N);
vector<int> f(N,-1e3);
int q;
cin>>q;

while(q--)
{
    char op;
    cin>>op;
    
    if(op=='I')
    {
        int x;
        cin>>x;
        
        A.push(x);
        sum[A.size()]=sum[A.size()-1]+A.top();
        f[A.size()]=max(f[A.size()-1],sum[A.size()]);
    }
    else if(op=='L')
    {
        if(!A.empty())
        {
        B.push(A.top());
        A.pop();
        }
    }
    else if(op=='D')
    {
        if(!A.empty())
        {
            A.pop();
        }
    }
    else if(op=='R')
    {
        if(!B.empty())
        {
        A.push(B.top());
        B.pop();
        }
        sum[A.size()]=sum[A.size()-1]+A.top();
        f[A.size()]=max(f[A.size()-1],sum[A.size()]);
        
    }
    else
    {
        int k;
        cin>>k;
        cout<<f[k]<<endl;
    }
}


    return 0;
}




















#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
cosnt int N=1e6+10;
int f[N]={0};
int Max[N]={0};

signed main()
{
ios::sync_with_stdio(0);
cout.tie(0);
cin.tie(0);

stack<int> front;
stack<int>  back;
int q;
cin>>q;

while(q--)
{
    char op;
    cin>>op;

    int cnt=0;

    if(op=='I')
    {
        int x;
        cin>>x;

     front.push(x);    
     cnt++;
     f[cnt]=f[cnt-1]+x;
     Max[cnt]=max(f[cnt],Max[cnt-1]);
    }
    else if(op=='D')
    {
      if(!front.empty())
      {
        front.pop();
        cnt--;
      }
    }
    else if(op=='L')
    {
        if(!front.empty())
        {
            int x=front.top();
            front.pop();
            back.push(x);
            cnt--;
        }
    }
    else if(op=='R')
    {
        if(!back.empty())
        {
            int x=back.top();
            back.pop();
            front.push(x);
            cnt++;
        }
    }
    else
    {
     cout<<Max[cnt]<<endl;
    }
}


    return 0;
}