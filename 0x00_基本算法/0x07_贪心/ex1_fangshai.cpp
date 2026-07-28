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


