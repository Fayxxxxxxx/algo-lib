ll exgcd(ll a,ll b,ll& x,ll& y)
{
    if(b==0)
    {
        x=1;
        y=0;

        return a;
    }

    ll x1,y1;
   
    ll d=exgcd(b,a%b,x1,y1);
    //再最后一层得到x和y 然后
    //递归回来
    x=y1;
    y=x1-a/b*y1;

    return d;
}