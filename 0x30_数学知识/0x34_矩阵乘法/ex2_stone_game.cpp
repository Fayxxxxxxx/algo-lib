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
const int MAXD=66;
int n,m,act;
ll t;

int N,D;

vs board;
vs ops;
struct matrix
{
 ll a[MAXD][MAXD];

 matrix()
 {
    memest(a,0,sizeof(a));
 }
};
matrix identity()
{
    matrix I;
    for(int i=0;i<D;i++)
    {
        I.a[i][i]=1;
    }

    return I;
}
matrix mul(matrix&A,matrix&B)
{
    matrix C;
    for(int i=0;i<D;i++)
    {
        for(int k=0;k<D;k++)
        {
            if(A.a[i][k]==0)continue;
            for(int j=0;j<D;j++)
            {
                if(B.a[j][k]==0)continue;
                C.a[i][j]+=A.a[i][k]*B.a[k][j];
            }
        }
    }

    return C;
}
matrix qpow(matrix&B,ll b)
{
    matrix res=identity();

    while(b)
    {
        if(b&1)res=mul(res,B);
        b>>=1;
        B=mul(B,B);
    }

    return res;
}

matrix get_matrix(int sec)
{
    matrix A;
    A.a[N][N]=1;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int from=i*m+j;
            int id=board[i][j]-'0';

            string &s=ops[id];

            char op=s[sec%s.size()];

            if(op>='0'&&op<='9')
            {
                A.a[from][from]+=1;
                A.a[from][N]=op-'0';//N是数字位
            }
            else if(op!='D')
            {
               int ni=i;
               int nj=j;

               if(op=='N')i--;
               if(op=='S')i++;
               if(op=='W')j--;
               if(op=='E')j++;

               if(ni>=0&&ni<n&&nj>=0&&nj<m)
               {
                int to=ni*m+nj;

                A.a[to][from]+=1;
               }
            }
        }
    }

    return A;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n>>m>>t>>act;

board.resize(n);

for(int i=0;i<n;i++)cin>>board[i];

ops.resize(act);

for(int i=0;i<act;i++)cin>>ops[i];
N=n*m;
D=N+1;

int p=1;
for(int i=0;i<act;i++)
{
    p=lcm(p,(int)ops[i].size());
}
vector<matrix> step(p);
for(int i=0;sec<p;sec++)
{
    step[sec]=get_matrix(sec);
}
matrix cycle=identity();

for(int sec=0;sec<p;sec++)
{
    cycle=mul(step[sec],cycle);
}

ll q=t/p;
int r=t%p;

matrix total=qpow(cycle,q);


for(int sec=0;sec<r;sec++)
{
    total=mul(step[sec],total);
}

ll ans=0;

for(int i=0;i<N;i++)
{
    ans=max(ans,total.a[i][N]);
}

cout<<ans<<endl;



    return 0;
}