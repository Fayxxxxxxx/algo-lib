//算将n个数分为k个数的写法一定要掌握

//这题是对其进行限制了 必须相乘为偶数
//所以先求想成为奇数的 然后总数减去即可 
//注意最后一定要+mod 所有之和再%mod

class Solution {
public:
        vector<long long> c_nums;
        vector<long long> inv_nums;
    int mod=1e9+7;

    long long power(long long a,long long b)
    {
        long long res=1;

        a=a%mod;

        while(b)
        {
            if(b&1)
            {
                res=res*a%mod;
            }
            b>>=1;
            a=a*a%mod;
        }
        return res;
    }
    int inv(int num)
    {
        return power(num,mod-2);
    }

    int C(int m,int n)
    {
        return (c_nums[m]%mod*inv_nums[n]%mod*inv_nums[m-n]%mod)%mod;
    }
    int countValidSequences(int n, int k) {
        int N=n+5;
        
        c_nums.resize(N);
        inv_nums.resize(N);

        c_nums[0]=1;
        for(int i=1;i<=n;i++)
        {
            c_nums[i]=c_nums[i-1]%mod*i%mod;
        }
        
        inv_nums[n]=inv(c_nums[n]);
        for(int i=n-1;i>=0;i--)
        {
            inv_nums[i]=(inv_nums[i+1]%mod*(i+1)%mod)%mod;
        }

        int total=C(n-1,k-1);
        int odd=0;

        if((n-k)%2==0)
        {
            odd=C((n-k)/2+k-1,k-1);
        }

        return (total-odd+mod)%mod;
        // 以后写此类取模题一定要注意
        
    }
};