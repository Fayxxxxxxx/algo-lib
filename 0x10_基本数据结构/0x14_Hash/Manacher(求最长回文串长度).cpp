#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

const int N=2000005;

char t[N];
int d[N];

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

string s;
int tt=1;
while(cin>>s&&s!="END")
{
    int n=s.size();
    int m=0;
    
    t[++m]='#';
    for(int i=0;i<n;i++)
    {
        t[++m]=s[i];
        t[++m]='#';
    }
    int mid=0;
    int r=0;
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        if(i<=r)
        {
            int j=2*mid-i;
            d[i]=min(d[j],r-i);
        }
        else
        {
            d[i]=0;
        }

        while(i-d[i]-1>=1&&i+d[i]+1<=m&&
        t[i-d[i]-1]==t[i+d[i]+1])
        {
            d[i]++;
        }

        if(i+d[i]>r)
        {
            mid=i;
            r=i+d[i];
        }
        ans=max(ans,d[i]);
    }
    cout<<"Case "<<tt<<": "<<ans<<endl;
    
    tt++;
}



    return 0;
}