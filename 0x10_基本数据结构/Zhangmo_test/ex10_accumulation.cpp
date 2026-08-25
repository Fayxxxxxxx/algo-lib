#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
//从i开始到i+m-1 比如长度为2 那就是从0 到 1
const int N=200000+10;
using ull=unsigned long long;
int n,m,q;
const int P=131;
ull p[N],h[N];
ull h2[N];
string s1,s2;
void init()
{
p[0]=1;

for(int i=1;i<=n;i++)
{
    p[i]=p[i-1]*P;
    h[i]=h[i-1]*P+(s1[i]-'a'+1);
}
for(int i=1;i<=m;i++)
{
    h2[i]=h2[i-1]*P+(s2[i]-'a'+1);
}
}
ull get_num(int l,int r)
{
    return h[r]-h[l-1]*p[r-l+1];
}
ull get_num2(int l,int r)
{
    return h2[r]-h2[l-1]*p[r-l+1];
}
bool check(int l,int mid)//[l,l+mid-1]
{
return get_num(l,l+mid-1)==get_num2(1,mid);
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n>>m>>q;
cin>>s1>>s2;
s1=" "+s1;
s2=" "+s2;
init();
unordered_map<int,int> mp;
for(int l=1;l<=n;l++)//从l开始到n [l,n]
{
int left=0;
int right=n+1;

    while(right-left>1)
{
    int mid=left+(right-left)/2;
    check(l,mid)?left=mid:right=mid;
}
mp[left]++;
}

for(int i=0;i<q;i++)
{
    int x;
    cin>>x;
    cout<<mp[x]<<endl;
}


    return 0;
}