bool is_prime(int num)
{
    if(num<2){
        return false;
    }

    for(int i=2;i<=num/i;i++)//如果n存在两个同时大于根号n的因数 那么他本身一定大于n 
    //必要性矛盾 所以只需要检验到根号n就可以判断这个数是不是质数了 如果到根号n都没有数能
    //整除他那么这个数一定是质数
    {
        if(num%i){
            return false;
        }
    }
    return true;
}


vii res;
for(int i=2;i<=n/i;i++)
{
    if(n%i==0)
    {
        int cnt=0;

        while(n/i==0)
        {
            n/=i;
            cnt++;
        }
        res.push_back({i,cnt});
    }

    if(n>1)
    {
        res.push_back({1,n});
    }
}