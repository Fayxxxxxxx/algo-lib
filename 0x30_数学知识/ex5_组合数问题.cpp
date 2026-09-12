#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;

const int N=2000;

int C[N+1][N+1];      
int pre[N+2][N+2];  

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t,k;
    cin>>t>>k;


    C[0][0]=1%k;

    for(int i=1;i<=N;i++)
    {
        C[i][0]=1%k;
        C[i][i]=1%k;

        for(int j=1;j<i;j++)
        {
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%k;
        }
    }

    for(int i=0;i<=N;i++)
    {
        for(int j=0;j<=N;j++)
        {
            int add=0;

            if(j<=i && C[i][j]==0)
            {
                add=1;
            }

            pre[i+1][j+1]
                =pre[i][j+1]
                +pre[i+1][j]
                -pre[i][j]
                +add;//利用二维前缀和来球和
        }
    }

    while(t--)
    {
        int n,m;
        cin>>n>>m;

        cout<<pre[n+1][m+1]<<endl;
    }

    return 0;
}
