#include<bits/stdc++.h>
using namespace std;

int n,m;

int cal(vector<string>& ops,vector<int> &ts,int l,int bitset)
{
    int res=bitset;
    
    for(int i=0;i<n;i++)
    {
        if(ops[i]=="AND")
        {
            res=(res&((ts[i]>>l)&1));
        }
        else if(ops[i]=="OR")
        {
            res=(res|((ts[i]>>l)&1));
        }
        else
        {
            res=(res^((ts[i]>>l)&1));
        }
    }
    
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    cin>>n>>m;
    
    vector<string> ops(n);
    vector<int> ts(n);
    
    for(int i=0;i<n;i++)
    {
        cin>>ops[i]>>ts[i];
    }
    
    int bis0[31]={};
    int bis1[31]={};
    
    for(int i=30;i>=0;i--)
    {
        bis0[i]=cal(ops,ts,i,0);
        bis1[i]=cal(ops,ts,i,1);
    }
    
    long long ans=0;
    long long atk=0;
    
    for(int i=30;i>=0;i--)
    {
        if(bis1[i]>bis0[i]&&atk+(1<<i)<=m)
        {
            atk+=(1<<i);
            ans+=(1<<i);
        }
        else
        {
            ans+=(bis0[i]<<i);
        }
    }
    
    cout<<ans;
    
    
    return 0;
}