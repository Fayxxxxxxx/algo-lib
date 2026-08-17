#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define ull unsigned long long

const ull N=3e5+5;
ull p[N],h[N];
const int P=131;
string s;
int n;
void init()
{
 p[0]=1;

 for(int i=1;i<=n;i++)
 {
    p[i]=p[i-1]*P;
    h[i]=h[i-1]*P+(s[i]-'a'+1);
 }
}
ull get_num(int l,int r)
{
    return h[r+1]-h[l]*p[r-l+1];
}
int get_lcp(int x,int y)
{
    int left=0;
    int right=min(n-x,n-y)+1;

    while(right-left>1)
    {
        int mid=left+(right-left)/2;

        if(get_num(x,x+mid-1)==get_num(y,y+mid-1))
        {
            left=mid;
        }
        else
        {
            right=mid;
        }
    }
    return left;
}
bool cmp(int x,int y)
{
if(x==y)
{
    return false;
}

int len1=n-x;
int len2=n-y;

int lcp=get_lcp(x,y);

if(lcp==min(len1,len2))
{
    return len1<len2;
}

return s[x+lcp+1]<s[y+lcp+1];
}
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>s;
n=(int)s.size();
s=" "+s;
init();
vector<int> sa(n);
vector<int> height(n);

for(int i=0;i<n;i++)sa[i]=i;
sort(sa.begin(),sa.end(),cmp);

height[0]=0;
for(int i=1;i<n;i++)
{
    height[i]=get_lcp(sa[i-1],sa[i]);
}

for(int x:sa)cout<<x<<" ";
cout<<endl;
for(int x:height)cout<<x<<" ";
cout<<endl;
    return 0;
}






#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define ull unsigned long long
const ull N=1000005*2;
ull p[N],h1[N],h2[N];
int n,m;
char t[N];
const int P=131;
void init()
{
    p[0]=1;
    for(int i=1;i<=m;i++)
    {
        p[i]=p[i-1]*P;
        h1[i]=h1[i-1]*P+(t[i]-'a'+1);
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
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);
string s;
int tt=1;
while(cin>>s&&s!="END")
{
n=s.size();
int cnt=0;
t[++cnt]='#';

for(int i=0;i<n;i++)//要把s里面的数据都读取到
{
    t[++cnt]=s[i];
    t[++cnt]='#';
}
m=cnt;
init();
cout<<"Case"<<" "<<tt<<":"<<" ";
int ans=1;
for(int i=1;i<=m;i++)
{
    int left=-1;
    int right=min(i-1,m-i)+1;
    while(right-left>1)
    {
        int mid=left+(right-left)/2;
        if(get_num1(i-mid,i+mid)==get_num2(i-mid,i+mid))
   {
    left=mid;
   }
   else
   {
    right=mid;
   }
    }
    

   
   ans=max(ans,left);
}
cout<<ans<<endl;

tt++;
}


    return 0;
}