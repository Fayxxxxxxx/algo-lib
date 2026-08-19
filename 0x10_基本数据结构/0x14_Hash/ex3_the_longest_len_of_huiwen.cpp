#include<bits/stdc++.h>
using namespace std;

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
using ull=unsigned long long;
int n,m;
const int N=1000000*2+5;
const int P=131;
ull p[N],h1[N],h2[N];
string s;
char t[N];
void init()
{
    p[0]=1;
    for(int i=1;i<=m;i++)
    {
        p[i]=p[i-1]*P;
        h1[i]=h1[i-1]*P+(t[i]-'a'+1);
    }
    h2[m+1]=0;//多测的时候记得加上h2[m+1]=0; 因为依赖h2[m+1]位
    for(int i=m;i>=1;i--)
    {
        h2[i]=h2[i+1]*P+(t[i]-'a'+1);
    }
}
ull get_num1(int l,int r)
{
    return h1[r]-h1[l-1]*p[r-l+1];
}
ull get_num2(int l,int r)
{
    return h2[l]-h2[r+1]*p[r-l+1];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt=1;
    while(cin>>s&&s!="END")
    {
        cout<<"Case "<<tt<<": ";
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
        int ans=1;
        for(int i=1;i<=m;i++)//这里t数组就是从1开始的 来计算长度 所以长度可能为0 所以left=-1 其实取0也可以
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