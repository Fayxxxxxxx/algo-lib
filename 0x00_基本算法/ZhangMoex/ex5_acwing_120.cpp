#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
int n;
struct equip
{
 int s,e,d;
};

int get_num(vector<equip>& equips,int x)
{
    int ans=0;

    for(int i=1;i<=n;i++)
    {
        if(equips[i].s<=x)
        {
        int end=min(equips[i].e,x);
        ans+=(end-equips[i].s)/equips[i].d+1;
        }
       
    }
    return ans;
}
void solve()
{
    
    cin>>n;
    
    int Min=LLONG_MAX;
    int Max=LLONG_MIN;

    vector<equip> equips(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>equips[i].s>>equips[i].e>>equips[i].d;
        Min=min(Min,equips[i].s);
        Max=max(Max,equips[i].e);
    }
    
    if(!(get_num(equips,Max)&1))
    {
        cout<<"There's no weakness."<<endl;
        return ;
    }
    int left=Min-1;
    int right=Max+1;

    while(right-left>1)
    {
        int mid=left+(right-left)/2;

        if((get_num(equips,mid)-get_num(equips,left))&1)
        {
            right=mid;
        }
        else
        {
            left=mid;
        }
    }

    cout<<right<<" "<<get_num(equips,right)-get_num(equips,right-1)<<endl;

}
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int T;
cin>>T;
while(T--)
{
    solve();
}


    return 0;
}