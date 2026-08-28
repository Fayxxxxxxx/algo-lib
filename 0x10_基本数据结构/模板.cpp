//1.hash

const int N=1e5;
using ull=unsigned long long;
ull p[N],h[N];
int n=s.size();//未加空格之前
const int P=131;
void init(string s)
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
    return h[r]-h[l-1]*p[r-l+1];
}

//2.kmp
string s;
string p;
cin>>s>>p;

int n=p.size();
int m=s.size();

s=" "+s;
p=" "+p;

vi nex(n+1);

for(int i=2,j=0;i<=n;i++)
{
    while(j&&p[i]!=p[j+1])
    {
        j=nex[j];
    }
    
    if(p[i]==p[j+1])
    {
        j++;
    }

    nex[i]=j;
}

for(int i=1,j=0;i<=m;i++)
{
    while(j&&s[i]!=p[j+1])
    {
       j=nex[j];
    }

    if(p[i]==p[j+1])
    {
        j++;
    }

    if(j==m)
    {
        cout<<i-m+1<<endl;

        j=nex[j];//保底
    }
}

//sa
const int N=1e5;
vector<int> sa;
vector<int> height;
string s;
using ull=unsigned long long;
int n=s.size();

sa.resize(n);
height.resize(n);
ull h[N],p[N];
const int P=131;
void init(string s)
{
    p[0]=1;
    for(int i=1;i<=n;i++)
    {
        h[i]=h[i-1]*P+(s[i-1]-'a'+1);
        p[i]=p[i-1]*P;
    }
}
ull get_num(int l,int r)
{
    return h[r+1]-h[l]*p[r-l+1];
}
int get_lcp(int x,int y)
{
    int left=0;
    int right=max(n-x,n-y)+1;

    while(right-left>1)
    {
        int mid=left+(right-left)/2;

        get_num(x,x+mid-1)==get_num(y,y+mid-1)?left=mid:right=mid;
    }
    return left;
}

bool cmp(int x,int y)
{
    if(x==y)
    {
        return true;
    }

    int len1=n-x;
    int len2=n-y;
    int len=get_lcp(x,y);

    if(len==min(len1,len2))
    {
        return len1<len2;
    }

    return s[x+len+1]<s[y+len+1];
}

for(int i=0;i<n;i++)
{
    sa[i]=i;
}
sort(sa.begin(),sa.end(),cmp);


//马拉车大法
string s;
cin>>s;
int cnt=0;
char t[N];
t[++cnt]='#';
for(int i=0;i<s.size();i++)
{
    t[++cnt]=s[i];
    t[++cnt]='#';
}
int d[N];
int mid=0;
int r=0;
for(int i=1;i<=cnt;i++)
{
if(i+d[i]<r)
{
    int j=2*mid-i;

    d[i]=max(d[j],r-i);
}
else
{
    d[i]=0;
}
while(i-d[i]-1>=1&&i+d[i]+1<=cnt&&t[i-d[i]-1]==t[i+d[i]+1])
{
    d[i]++;
}

if(i+d[i]>=r)
{
    mid=i;
    r=i+d[i];
}

ans=max(ans,d[i]);
}


//最小表示法
string s;
cin>>s;
int n=s.size();
s=s+s;
int k=0;
int i=0;
int j=1;

while(i<n&&j<n)
{
    while(k<n&&s[i+k]==s[j+k])
    {
        k++;
    }

   if(s[i+k]>s[j+k])
   {
    i=i+k+1;
   }
   else
   {
    j=j+k+1;
   }

   if(i==j)j++;

}
ans=min(i,j);

for(int k=i;k<i+ans;k++)
{
    cout<<s[k];
}

//trie

const int N=1e5;
int son[N][26];
int cnt[N];
int pass[N];
int idx;
void insert(string s)
{
    int u=0;
    for(char x:s)
    {
        int y=x-'a';

        if(son[u][y]==0)
        {
            son[u][y]=++idx;
        }
        u=son[u][y];
        pass[u]++;
    }
    cnt[u]++;
}

bool query(string s)
{
    int u=0;
    for(char x:s)
    {
        int y=x-'a';

        if(son[u][y]==0)
        {
            return false;
        }
        u=son[u][y];
    }

    return true;
}


//给你一堆数 求其中两个数异或的最大值
const int N=1e5;
int son[N][2];
int idx;
void insert(int x)
{
    int u=0;
    for(int i=30;i>=0;i--)
    {
        int bit=(1>>x)&1;

        if(!son[u][bit])
        {
           son[u][bit]=++idx;
        }
        u=son[u][bit];
    }
}
ll query(int x)
{
    int u=0;
    ll res=0;
    
    for(int i=30;i>=0;i--)
    {
        int bit=(x>>i)&1;

        if(son[u][bit^1])
        {
          res|=(1<<i);
          u=son[u][bit^1];
        }
        else
        {
            u=son[u][bit];
        }
    }
    return res;
}

vi mul_v(vi& a,vi& b)
{
    vi c(a.size()+b.size());
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<b.size();j++)
        {
            c[i+j]+=a[i]*b[j];
        }
    }

    int t=0;
    for(int i=0;i<c.size();i++)
    {
        t+=c[i];
        c[i]=t%10;
        t/=10;
    }

    while(c.size()>1&&c.back()==0)c.pop_back();

    return c;
}

cout<<ans.back();
for(int i=ans.size()-2;i>=0;i--)
{
    cout<<setw(4)<<setfill('0')<<ans[i];
}
cout<<endl;


vi mul_int(vi& a,int b)
{
    int t=0;
    vi c;
    for(int i=0;i<a.size()||t;i++)
    {
        if(i<a.size())t+=a[i]*b;
        c.push_back(t%10);
        t/=10;
    }
    return c;
}

vi div_int(vi&a,int b)
{
    vi c;

    int r=0;

    for(int i=a.size()-1;i>=0;i--)
    {
       r=r*10+a[i];
       c.push_back(r/b);
       r%=b;
    }
    reverse(c.begin(),c.end());
    while(c.size()>1&&c.back()==0)c.pop_back();

    return c;
}