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
const int N=35;
ll dp[31][16][11][8][7];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int k;

while(cin>>k&&k)
{
    vi n(6,0);
    for(int i=1;i<=k;i++)cin>>n[i];
    memset(dp,0,sizeof dp);
    dp[0][0][0][0][0]=1;
    for(int a=0;a<=n[1];a++)
    {
        for(int b=0;b<=n[2];b++)
        {
            for(int c=0;c<=n[3];c++)
            {
                for(int d=0;d<=n[4];d++)
                {
                    for(int e=0;e<=n[5];e++)
                    {
                        if(a<n[1])
                        {
                            dp[a+1][b][c][d][e]+=dp[a][b][c][d][e];
                        }

                        if(b<n[2]&&b<a)
                        {
                            dp[a][b+1][c][d][e]+=dp[a][b][c][d][e];
                        }

                        if(c<n[3]&&c<b)
                        {
                            dp[a][b][c+1][d][e]+=dp[a][b][c][d][e];
                        }

                        if(d<n[4]&&d<c)
                        {
                            dp[a][b][c][d+1][e]+=dp[a][b][c][d][e];
                        }

                        if(e<n[5]&&e<d)
                        {
                            dp[a][b][c][d][e+1]+=dp[a][b][c][d][e];
                        }
                    }
                }
            }
        }
    }
    cout<<dp[n[1]][n[2]][n[3]][n[4]][n[5]]<<endl;

}

    return 0;
}