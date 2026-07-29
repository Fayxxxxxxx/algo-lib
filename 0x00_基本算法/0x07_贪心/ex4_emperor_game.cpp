#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

vector<int> mul(vector<int>& a,int b)
{
    vector<int> c;
    int t=0;

    for(int i=0;i<a.size()||t;i++)
    {
        if(i<a.size())
        {
            t+=b*a[i];
        }
        c.push_back(t%10);
        t/=10;
    }
 return c;
}

vector<int> div(vector<int>& a,int b)
{
    vector<int> c;
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

bool v_cmp(vector<int>& a,vector<int>& b)
{
    if(a.size()!=b.size())
    {
        return a.size()>b.size();
    }

    for(int i=a.size()-1;i>=0;i--){
        if(a[i]>b[i])
        {
            return true;
        }
        else if(a[i]<b[i])
        {
            return false;
        }
    }
    return true;
}
struct man
{
 int left;
 int right;
};


bool cmp(man& a,man& b)
{
  return a.left*a.right<b.left*b.right;//这里不能写<=
}
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

int n;
cin>>n;

vector<man> mans(n+1);
for(int i=0;i<n+1;i++)
{
    cin>>mans[i].left>>mans[i].right;
}
sort(mans.begin()+1,mans.end(),cmp);

vector<int> prod={mans[0].left};
vector<int> max_gold={0};

for(int i=1;i<n+1;i++)
{
    vector<int> gold=div(prod,mans[i].right);
    if(v_cmp(gold,max_gold))max_gold=gold;
    prod=mul(prod,mans[i].left);
}
for(int i=max_gold.size()-1;i>=0;i--)
{
    cout<<max_gold[i];
}


    return 0;
}

