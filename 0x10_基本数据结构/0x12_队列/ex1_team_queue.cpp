#include<bits/stdc++.h>
using namespace std;


#define endl '\n'

const int N=1010;
const int M=1e6+1;
int id[M];
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int t;
int k=1;
while(cin>>t&&t)
{
    cout<<"Scenario #"<<k++<<endl;   
    for(int i=0;i<t;i++)
    {
      int n;
      cin>>n;

      while(n--)
      {
        int x;
        cin>>x;
        id[x]=i;
      }
    }

    vector<queue<int>> person(N);
    queue<int> base;
    string op;

    while(cin>>op&&op!="STOP")
    {
        if(op=="ENQUEUE")
        {
            int x;
            cin>>x;

            if(person[id[x]].empty())base.push(id[x]);
            person[id[x]].push(x);
        }
        else
        {
            int ids=base.front();
           cout<<person[ids].front()<<endl;
           person[ids].pop();
           if(person[ids].empty())base.pop();
        }
    }
    cout<<endl;
}



    return 0;
}