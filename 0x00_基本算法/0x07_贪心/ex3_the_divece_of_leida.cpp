#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
int n,d;

struct island
{
    double x;
    double y;
};

struct range
{
 double left;
 double right;
};

bool cmp(range& a,range& b)
{
    if(a.right!=b.right)
    {
        return a.right<=b.right;
    }S
    return a.left<=b.left;
}

signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

cin>>n>>d;

vector<island> islands(n);

for(int i=0;i<n;i++)
{
    cin>>islands[i].x>>islands[i].y;

    if(islands[i].y>d)
    {
        cout<<-1<<endl;
        return 0;
    }
}

vector<range> ranges(n);

for(int i=0;i<n;i++)
{
    double x=islands[i].x;
    double y=islands[i].y;

    double x2=x+sqrt(d*d-y*y);
    double x1=x-sqrt(d*d-y*y);

    ranges[i].left=x1;
    ranges[i].right=x2;
}
sort(ranges.begin(),ranges.end(),cmp);

double right=-1e5;

int cnt=0;

for(int i=0;i<n;i++)
{
if(ranges[i].left>right)
{
    cnt++;
    right=ranges[i].right;
}
}

cout<<cnt<<endl;



    return 0;
}

