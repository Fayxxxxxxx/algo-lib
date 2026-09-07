ll cal(ll a,ll p)
{
    ll ans=0;
    while(a)
    {
       n/=p;//相当于就是n/p+n/p^2+n/p^3 这是对某个值去算贡献了多少次
       ans+=n;
    }

    return ans;
}