#include<bits/stdc++.h>
using namespace std;

void print(int n)
{
    in
    for(int i=2;i*i<=n;i++)
    {
        int cnt=0;
        while(n%i==0)
        {
           cnt++;
           n/=i;
        }

        cout<<i<<"^"<<cnt<<endl;
    }

    
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

int n;
cin>>n;

print(n);


    return 0;
}