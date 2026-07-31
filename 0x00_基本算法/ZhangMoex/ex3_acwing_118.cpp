#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int N=729;
int arr[8]={0,1,3,9,27,81,243,729};
vector<vector<bool>> G(N,vector<bool>(N,false));
void draw(int len,int x,int y){
    if(len==1)
    {
        G[x][y]=true;
        return ;
    }

    int true_len=len/3;

    draw(true_len,x,y);
    draw(true_len,x,y+2*true_len);
    draw(true_len,x+true_len,y+true_len);
    draw(true_len,x+2*true_len,y);
    draw(true_len,x+2*true_len,y+2*true_len);
}    
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n;
while(cin>>n&&n!=-1)
{
    int len=arr[n];

   draw(len,0,0);

   for(int i=0;i<len;i++)
   {
    for(int j=0;j<len;j++)
    {
        if(G[i][j])
        {
            cout<<"X";
        }
        else
        {
            cout<<" ";
        }
    }
    cout<<endl;
   }
   cout<<"-"<<endl;

}


    return 0;
}




#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int arr[8]={0,1,3,9,27,81,243,729};
vector<vector<bool>> _empty(730,vector<bool>(730));
vector<vector<bool>> grid(730,vector<bool>(730));
void draw(int n,int x,int y)
{
    if(n==1)
    {
        grid[x][y]=true;
        return ;
    }

    int len=arr[n-1];

    draw(n-1,x,y);
    draw(n-1,x,y+2*len);
    draw(n-1,x+len,y+len);
    draw(n-1,x+2*len,y);
    draw(n-1,x+2*len,y+2*len);

}
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n;

while(cin>>n&&n!=-1)
{
    grid=_empty;

    draw(n,0,0);

    for(int i=0;i<arr[n];i++)
    {
        for(int j=0;j<arr[n];j++)
        {
            if(grid[i][j])
            {
                cout<<"X";
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<endl;
    }

    cout<<"-"<<endl;
}



    return 0;
}