#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int cnt=0;
int in=1;
vector<int> out;
stack<int> inner;
int n;
void dfs()
{
    if(cnt>=20)
    {
        return ;
    }
    
    if((long long)out.size()==n)
    {
        for(int x:out)
        {
            cout<<x;
        }
        cout<<endl;
        cnt++;
       return ;
    }
    
    if(!inner.empty())
    {
        int x=inner.top();
        inner.pop();
        out.push_back(x);
        dfs();
        out.pop_back();
        inner.push(x);
    }
    if(in<=n)
    {
    inner.push(in);
    in++;
    dfs();
    inner.pop();
    in--;   
    }
    
}

signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n;

dfs();



    return 0;
}