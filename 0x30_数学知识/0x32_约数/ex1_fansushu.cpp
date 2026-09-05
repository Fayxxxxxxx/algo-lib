#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
using vc=vector<char>;
using vb=vector<bool>;
using vs=vector<string>;
const int INF=0x3f3f3f3f;

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
ll n;
cin>>n;
ll max_num;
ll max_cnt;
for(ll i=1;i<=(ll)sqrt(n);i++)
{
     ll cnt=0;
    for(ll p=1;p<=i/p;p++)
    {
       
       if(i%p==0)
       {
        cnt++;

        if(p!=i/p)
        {
            cnt++;
        }
       }
    }

    if(cnt>max_cnt)
    {
        max_num=i;
    }
}

for(ll i=(ll)sqrt(n);i<=n;i++)
{
     ll cnt=0;
    for(ll p=1;p<=i/p;p++)
    {
       
       if(i%p==0)
       {
        cnt++;

        if(p!=i/p)
        {
            cnt++;
        }
       }
    }

    if(cnt>max_cnt)
    {
        max_num=i;
    }
}
cout<<max_num<<endl;


    return 0;
}
//上面的废物TLE


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
using vc=vector<char>;
using vb=vector<bool>;
using vs=vector<string>;
const int INF=0x3f3f3f3f;
ll n;
ll ans=1;
ll best_cnt=1;
int arr[10]={2,3,5,7,11,13,17,19,23,29};
void dfs(int u,int last,ll num,ll d)
{
if(d>best_cnt||(d==best_cnt&&num<ans))
{
    best_cnt=d;
    ans=num;
}

if(u>=10)return ;

ll cur=num;
for(int e=1;e<=last;e++)
{
    if(cur>n/arr[u])
    {
       break;
    }
    cur*=arr[u];

    dfs(u+1,e,cur,d*(e+1));
}
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n;
dfs(0,31,1,1);

cout<<ans<<endl;


    return 0;
}