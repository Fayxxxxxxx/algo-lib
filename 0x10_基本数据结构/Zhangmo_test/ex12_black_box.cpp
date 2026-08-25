#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

    int m,n;
    cin>>m>>n;

    vi a(m);

    for(int i=0;i<m;i++)
        cin>>a[i];

    vi u(n);

    for(int i=0;i<n;i++)
        cin>>u[i];

    priority_queue<int> left;//左边大根堆

    priority_queue<int,vi,greater<int>> right;//右边小根堆

    int pos=0;

    for(int i=0;i<n;i++)
    {
        while(pos<u[i])
        {
            int x=a[pos++];
            left.push(x);

            right.push(left.top());
            left.pop();
        }

        cout<<right.top()<<endl;
        left.push(right.top());
        right.pop();
    }

    return 0;
}
