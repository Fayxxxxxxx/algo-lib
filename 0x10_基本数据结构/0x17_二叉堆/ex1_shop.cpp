//这个思路真的太巧妙了 第k天的情况下 
// 只有日期大于等于第k天的商品才可以销售 这个思路真牛逼

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

using pii=pair<int,int>;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    while(cin>>n)
    {
        vector<pii> a(n);

        int Max_time=0;

        for(int i=0;i<n;i++)
        {
            int val,date;
            cin>>val>>date;

            a[i]={date,val};

            Max_time=max(Max_time,date);
        }

        // deadline 从大到小
        sort(a.begin(),a.end(),greater<pii>());

        priority_queue<int> pq;

        long long ans=0;
        int j=0;

        for(int day=Max_time;day>=1;day--)//这一招惊为天人
        {
            // 把所有截止日期 >= day 的任务加入
            while(j<n && a[j].first>=day)//因为一天只能卖一件商品
            {
                pq.push(a[j].second);
                j++;
            }

            // 今天选价值最大的
            if(!pq.empty())
            {
                ans+=pq.top();
                pq.pop();
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}


//一般思路 可以思考一下 第一天 我可以卖掉一个商品 第二天 我可以卖掉两个商品 
//第k天我可以卖掉K个商品 也就是预留位置的思想
//而这预留的位置我为了得到最大的值 我当然把最小的T掉 放进去大的

//所以我只需要先按照deadline排序
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

bool cmp(pii&a,pii&b)
{
    return a.second<b.second;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n;

while(cin>>n)
{
    vector<pii> nums(n);

    for(int i=0;i<n;i++)
    {
        cin>>nums[i].first>>nums[i].second;
    }
    
sort(nums.begin(),nums.end(),cmp);
priority_queue<int,vi,greater<int>> pq;
for(auto [val,date]: nums)
{
    pq.push(val);

    if(pq.size()>date)//假设第k天我可以选k个 我目前选的个数已经超过k了 我必须把
    //最小的那个pop掉
    {
        pq.pop();
    }
}

int ans=0;
while(!pq.empty())
{
    ans+=pq.top();
    pq.pop();
}
cout<<ans<<endl;


}

    return 0;
}