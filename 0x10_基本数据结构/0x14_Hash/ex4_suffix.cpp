#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define ull unsigned long long

const ull N=3e5+5;
const ull P=131;
ull p[N],h[N];
vector<int> sa;
vector<int> height;
string s;
int n;
ull get_hash(int l,int r)
{
    return h[r+1]-h[l]*p[r-l+1];//0-base
}

int get_lcp(int x,int y)
{
    int left=0;
    int right=min(n-x,n-y)+1;
    
    while(right-left>1)
    {
        int mid=left+(right-left)/2;

        if(get_hash(x,x+mid-1)==get_hash(y,y+mid-1))
        {
            left=mid;//left维持满足的一边
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
    int len1=n-x;//0-base
    int len2=n-y;

    int lcp=get_lcp(x,y);

    if(lcp==min(len1,len2))//字典序 前面都一样 谁短谁字典序小
    {
        return len1<len2;
    }

    return s[x+lcp+1]<s[y+lcp+1];//s前面加了一个空格 那么这里就+1就好了
}
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>s;

n=s.size();
s=" "+s;
p[0]=1;

for(int i=1;i<=n;i++)
{
    p[i]=p[i-1]*P;
    h[i]=h[i-1]*P+(s[i]-'a'+1);
}
sa.resize(n);
height.resize(n);
//x 表示从x 开始而n-x代表长度 0-base

for(int i=0;i<n;i++)sa[i]=i;//从第几位开始 然后向后算后缀
//如 banana i=0的时候得到的后缀就是 banana
//i=1的时候是 anana
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