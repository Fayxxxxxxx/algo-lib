#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define ull unsigned long long

const ull P=131;
const ull N=1000005;
ull p[N],h[N];

void init(string s)
{
    int n=(int)s.size()-1;
    
    p[0]=1;
    for(int i=1;i<=n;i++)
    {
        p[i]=p[i-1]*P;
        h[i]=h[i-1]*P+(s[i]-'a'+1);
    }
}
ull get_num(int l,int r)
{
    return h[r]-h[l-1]*p[r-l+1];
}
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);

string s;
cin>>s;
s=" "+s;
int n;
cin>>n;
init(s);
for(int i=0;i<n;i++)
{
    int l1,r1,l2,r2;
    cin>>l1>>r1>>l2>>r2;
    
    if(get_num(l1,r1)==get_num(l2,r2))
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
}



    return 0;
}