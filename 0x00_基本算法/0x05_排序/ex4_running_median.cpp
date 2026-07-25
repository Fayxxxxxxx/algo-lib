1 5
1 3 5 7 9 
2 5
9 9 9 9 
3 12
23 23 23 23 23 23 103 103 103 103 103 103 


#include<bits/stdc++.h>
using namespace std;

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

priority_queue<int> left;
priority_queue<int,vector<int>,greater<int>> right;

int p;
cin>>p;


while(p--)
{
    int id,m;
    cin>>id>>m;

    cout<<id<<" "<<(1+m)/2<<endl;
    int cnt=0;
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        
        if(left.empty()||left.top()>=x)
        {
            left.push(x);
        }
        else
        {
            right.push(x);
        }

        if(left.size()-1>right.size())
        {
            right.push(left.top());
            left.pop();
        }
        else if(left.size()<right.size())
        {
            left.push(right.top());
            right.pop();
        }

        if((left.size()+right.size())&1)
        {
            cnt++;

            cout<<left.top()<<" ";

            if(cnt%10==0)
            {
              cout<<endl;
            }
        }
    }  
    cout<<endl;
}   


    return 0;
}