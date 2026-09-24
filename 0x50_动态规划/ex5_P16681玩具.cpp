卷云今天在家中发现了一个玩具。这个玩具由若干个圆形区域构成，按照下图所示的方式排列：



其中第一列、第三列和第五列各有 341,799 个圆形区域，而第二列和第四列各有 2 个圆形区域。

现在，Dylan 想要给每一个圆形区域都填入一个小写字母，使得相切的两个圆形区域中的字母不能都是元音。

其中，元音是指 a,e,i,o,u 这五个字母。

现在，卷云的好朋友小 🧿 想要知道填字母的方案数。请你帮他求出结果，并对 998,244,353 取模后输出。


//这题对我来说顶级好题 对状态变化的确定和讨论
//设dp[i][s][e] 为长度为i 开头为s 第i位字符为e的方案数

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int mod=998244353;
vector<vector<vector<int>>> dp(341799,vector<vector<int>>(2,vector<int>(2)));
	
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	//1.记录到第几个
	//2.头是什么
	//3.当前的尾是什么
	
	
	dp[0][1][1]=5;
	dp[0][0][0]=21;
	dp[0][1][0]=0;
	dp[0][0][1]=0;
	
	for(int i=1;i<341799;i++)
	{
		dp[i][1][0]=((dp[i-1][1][0]%mod*21)%mod+(dp[i-1][1][1]%mod*21)%mod)%mod;
		dp[i][1][1]=(dp[i-1][1][0]%mod*5)%mod;
		
		dp[i][0][1]=(dp[i-1][0][0]%mod*5)%mod;
		dp[i][0][0]=((dp[i-1][0][0]%mod*21)%mod+(dp[i-1][0][1]%mod*21)%mod)%mod;
	 } 
	
	//这样就算出来了四种头尾的情况
	
	int ans=0;
	
	for(int x1=0;x1<=1;x1++)
	for(int x3=0;x3<=1;x3++)
	for(int x5=0;x5<=1;x5++)
	for(int y1=0;y1<=1;y1++)
	for(int y3=0;y3<=1;y3++)
	for(int y5=0;y5<=1;y5++)
	{
		int xa=x1||x3?21:26;
		int xb=x3||x5?21:26;
		int xc=y1||y3?21:26;
		int xd=y3||y5?21:26;
		
		ans=(ans+dp[341798][x1][y1]%mod*dp[341798][x3][y3]%mod*dp[341798][x5][y5]%mod
		*xa%mod*xb%mod*xc%mod*xd%mod
		)%mod;
	}
	
	cout<<ans<<endl;
	
	return 0;
}









//自己的版本

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
using vc=vector<char>;
using vb=vector<bool>;
using vs=vector<string>;
using i128=__int128_t;
const int INF=0x3f3f3f3f;
const int N=341799;
ll dp[N][2][2];
int mod=998244353;
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
dp[0][0][0]=5;
dp[0][1][1]=21;
    for(int i=1;i<N;i++)
    {
        dp[i][0][1]=(dp[i-1][0][0]%mod+dp[i-1][0][1]%mod)*21%mod;
        dp[i][0][0]=dp[i-1][0][1]*5%mod;
        dp[i][1][0]=dp[i-1][1][1]*5%mod;
        dp[i][1][1]=(dp[i-1][1][0]%mod+dp[i-1][1][1]%mod)*21%mod;
    }

    //现在得到了00 01 10 11
    //然后分别考虑四个连接点的

    ll ans=0;

    for(int xa=0;xa<=1;xa++)
    for(int xb=0;xb<=1;xb++)
    for(int xc=0;xc<=1;xc++)
    for(int xd=0;xd<=1;xd++)
    for(int xe=0;xe<=1;xe++)
    for(int xf=0;xf<=1;xf++)
    for(int xg=0;xg<=1;xg++)
    for(int xh=0;xh<=1;xh++)
    for(int xj=0;xj<=1;xj++)
    for(int xi=0;xi<=1;xi++)
                                   {
                                       if(xc==0)
                                       {
                                           if(xa==xc||xe==xc)
                                           {
                                               continue;
                                           }
                                       }
                                       if(xd==0)
                                       {
                                             if(xb==xd||xd==xf)
                                             {
                                                 continue;
                                             }
                                       }
                                       if(xg==0)
                                       {
                                           if(xg==xe||xg==xi)
                                           {
                                               continue;
                                           }
                                       }

                                       if(xh==0)
                                       {
                                           if(xf==xh||xh==xj)
                                           {
                                            continue;
                                            }
                                       }

                                       ll axc=(xc==0?5:21);
                                       ll axd=(xd==0?5:21);
                                       ll axg=(xg==0?5:21);
                                       ll axh=(xh==0?5:21);

                                       ans=(ans+(i128)dp[N-1][xa][xb]%mod*dp[N-1][xe][xf]%mod*dp[N-1][xi][xj]%mod*axc%mod*axd%mod*axg%mod*axh%mod)%mod;

    }
    cout<<ans<<endl;
    return 0;
}