// #include<bits/stdc++.h>
// using namespace std;

// #define int long long
// int M=200001;
// int N=200001;

// vector<int> sci(N);
// vector<int> film_v(M);
// vector<int> film_w(M);

// struct tmp
// {
//  bool operator()(auto& a,auto& b)
//  {
//     return a.second>b.second;
//  }
// };
// signed main()
// {
// ios::sync_with_stdio(0);
// cin.tie(0);
// cout.tie(0);

// int n;
// cin>>n;

// for(int i=0;i<n;i++)
// {
//     cin>>sci[i];
// }
// int m;
// cin>>m;

// for(int i=0;i<m;i++)
// {
//     cin>>film_v[i];
// }
// for(int i=0;i<m;i++)
// {
//     cin>>film_w[i];
// }

// vector<int> b_copy=film_v;

// unordered_map<int,vector<int>> mp;

// for(int i=0;i<m;i++)
// {
//     mp[film_v[i]].push_back(i);
// }

// map<int,int> cal;

// for(int i=0;i<n;i++)
// {
//     int x=sci[i];

//     cal[x]++;
// }

// vector<pair<int,int>> nums(cal.begin(),cal.end());
// sort(nums.begin(),nums.end(),tmp());


//     return 0;
// }

//上面是失败的写法

//1.先做离散化

#include<bits/stdc++.h>
using namespace std;
const int N=2e5+20;
vector<int> cnt(N);
vector<int> uni(N);
vector<int> a(N);
vector<int> b(N);
vector<int> c(N);


vector<int> lang;
int find(int x)
{
    return lower_bound(uni.begin(),uni.end(),x)-uni.begin()+1;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

int n;
cin>>n;

for(int i=1;i<=n;i++)
{
    cin>>a[i];
    lang.push_back(a[i]);
}
int m;
cin>>m;

for(int i=1;i<=m;i++)
{
    cin>>b[i];
    lang.push_back(b[i]);
}

for(int i=1;i<=m;i++)
{
    cin>>c[i];
    lang.push_back(c[i]);
}
sort(lang.begin(),lang.end());

for(int i=0;i<lang.size();i++)
{
    if(i==0||lang[i-1]!=lang[i])
    {
        uni.push_back(lang[i]);
    }
}

for(int i=1;i<=n;i++)
{
    int id=find(a[i]);
    cnt[id]++;

}

int bestmovie=0;
int bestaudio=0;
int bestword=0;

for(int i=1;i<=m;i++)
{
    int audiocnt=cnt[find(b[i])];
    int wordcnt=cnt[find(c[i])];

    if(audiocnt>bestaudio||(audiocnt==bestaudio&&(wordcnt>bestword)))
    {
        bestmovie=i;
        bestaudio=audiocnt;
        bestword=wordcnt;
    }
}

if(bestmovie==0)
{
    cout<<1<<endl;

}
else
{
    cout<<bestmovie<<endl;
}

    return 0;
}