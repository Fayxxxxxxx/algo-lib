#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

struct cow
{
    int Min;
    int Max;
};

bool cmp_cow(cow& a,cow& b)
{
    if(a.Min!=b.Min)
    {
        return a.Min>=b.Min;
    }
    return a.Max>=b.Max;
}

struct cover
{
   int spf;
   int num;
};

bool cmp_cover(cover& a,cover& b)
{
    if(a.spf!=b.spf)
    {
        return a.spf>=b.spf;
    }
    return a.num>=b.num;
}
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

int c,l;
cin>>c>>l;

vector<cow> cows(c);

for(int i=0;i<c;i++)
{
    cin>>cows[i].Min>>cows[i].Max;
}

sort(cows.begin(),cows.end(),cmp_cow);

vector<cover> covers(l);

for(int i=0;i<l;i++)
{
    cin>>covers[i].spf>>covers[i].num;
}

sort(covers.begin(),covers.end(),cmp_cover);

int ans=0;

for(int i=0;i<c;i++)
{
    cow tmp=cows[i];
    int Min=tmp.Min;
    int Max=tmp.Max;

    for(int j=0;j<l;j++)
    {
        if(Min<=covers[j].spf&&covers[j].spf<=Max&&covers[j].num!=0)
        {
            covers[j].num--;
            ans++;
            break;
        }
    }
}

cout<<ans<<endl;
    return 0;
}



//另一种思路 反向的 排序Max 让需求最大的牛去用大的防晒霜 而小牛用小的防晒霜


#include<iostream>
#include<algorithm>
using namespace std;

const int N=100010;
int n,m,f[N];
struct T{
    int min,max;
}a[N];

bool cmp(T a,T b){
    return a.max<b.max;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i].min>>a[i].max;

    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        f[x]+=y; //注意这里可能累加
    }

    sort(a+1,a+n+1,cmp);

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=a[i].min;j<=a[i].max;j++){
            if(f[j]){
                f[j]--,ans++;
                break;
            }
        }
    }
    cout<<ans;

    return 0;
}


