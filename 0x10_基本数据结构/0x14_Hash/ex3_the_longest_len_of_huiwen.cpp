#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define ull unsigned long long

int m,n;
const ull N=2*1000000+5;
const ull P=131;
ull p[N],h1[N],h2[N];

char t[N];
void init()
{
p[0]=1;
for(int i=1;i<=m;i++)
{
    h1[i]=h1[i-1]*P+(t[i]-'a'+1);
    p[i]=p[i-1]*P;
}

for(int i=m;i>=1;i--)
{
    h2[i]=h2[i+1]*P+(t[i]-'a'+1);
}
}
int get_num1(int l,int r)
{
    return h1[r]-h1[l-1]*p[r-l+1];
}
int get_num2(int l,int r)
{
    return h2[l]-h2[r+1]*p[r-l+1];
}

bool check(int i,int r)
{
    return get_num1(i-r,i+r)==get_num2(i-r,i+r);
}

signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);
string s;
int tt=1;
while(cin>>s&&s!="END")
{
cout<<"Case"<<" "<<tt<<":"<<" ";
int n=s.size();
int cnt=0;
t[++cnt]='#';

for(int i=0;i<n;i++)
{
    t[++cnt]=s[i];
    t[++cnt]='#';
}
m=cnt;
init();
int ans=1;
for(int i=1;i<=m;i++)
{
    int left=-1;
    int right=min(m-i,i-1)+1;
    
    while(right-left>1)
    {
        int mid=left+(right-left)/2;

        check(i,mid)?left=mid:right=mid;//这里通过草稿纸上发现
        //得到的半径 刚好是满足的长度 实际上应该是2*r+1才是长度 
    }
    ans=max(ans,left);
}
cout<<ans<<endl;
tt++;
}

    return 0;
}