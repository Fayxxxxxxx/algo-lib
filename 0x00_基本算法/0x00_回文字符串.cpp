核心思想不是“一个个判断是不是回文”，而是：
一个回文数完全由它的前半部分决定

//所以我们只需要去枚举"前半部分" 然后镜像即可
vector<vector<ll>> pals(2);
void init_pal()//比如范围是1e9
{
const ll LIMIT=2000000002LL;
//1000000001保证了奇数回文字符串上限 LIMIT是偶数回文字符串上限

for(ll x=1;;x++)
{
    ll a=make_pal(x,true);
    ll b=make_pal(x,false);

    if(a>LIMIT&&B>LIMIT)break;

    if(a<=LIMIT)
    {
        pals[a&1].push_back(a);
    }
    if(b<=LIMIT)
    {
        pals[b&1].push_back(b);
    }
}
for(int i=0;i<2;i++)
{
sort(pals[i].begin(),pals[i].end());
pals[i].erase(unique(pals[i].begin(),pals[i].end()),pals[i].end());
}
}
ll make_pal(ll x,ll odd)
{
    ll res=x;

    if(odd)x/=10;

    while(x)
    {
        res=res*10+x%10;//把x从后面向前面加 相当于取反
        x/=10;
    }
    return res;
}

//判断回文
bool is_pal(ll x)
{
    string s=to_string(x);
    string t=s;

    reverse(t.begin(),t.end());
    if(t==s)
    {
        return true;
    }
    return false;
}









//甚至放在力扣里面他会卡测评 需要用static
using ll=long long;

class Solution {
public:
    ll make_pal(ll x,bool odd)
    {
        ll res=x;

        if(odd) x/=10;

        while(x)
        {
            res=res*10+x%10;
            x/=10;
        }

        return res;
    }

    long long minOperations(vector<int>& nums)
    {
        // 这两个只会创建一次
        static vector<ll> pals[2];
        static bool inited=false;

        if(!inited)
        {
            const ll LIMIT=2000000002LL;

            for(ll x=1;x<=99999;x++)
            {
                ll a=make_pal(x,false);
                ll b=make_pal(x,true);

                if(a<=LIMIT)
                    pals[a&1].push_back(a);

                if(b<=LIMIT)
                    pals[b&1].push_back(b);
            }

            for(int i=0;i<2;i++)
            {
                sort(pals[i].begin(),pals[i].end());

                pals[i].erase(
                    unique(pals[i].begin(),pals[i].end()),
                    pals[i].end()
                );
            }

            inited=true;
        }

        ll ans=0;

        for(int x:nums)
        {
            auto &v=pals[x&1];

            auto it=lower_bound(v.begin(),v.end(),x);

            ll dis=*it-x;

            if(it!=v.begin())
            {
                dis=min(dis,(ll)x-*(it-1));
            }

            ans+=dis/2;
        }

        return ans;
    }
};
