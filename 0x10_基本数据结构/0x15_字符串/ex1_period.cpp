#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    int tt=1;
    while(cin>>n&&n)
    {
        string s;
        cin>>s;
        s=" "+s;
        vector<int> nex(n+1);
        
        for(int i=2,j=0;i<=n;i++)
        {
            while(j&&s[i]!=s[j+1])
            {
                j=nex[j];
            }
            
            if(s[i]==s[j+1])
            {
                j++;
            }
            
            nex[i]=j;
        }
        
        cout<<"Test case #"<<tt<<endl;
        
        for(int i=2;i<=n;i++)
        {
            int len=i-nex[i];
            
            //t=i−nex[i]<i
            //t/i>1  才能满足重复次数>1 所以i%len要==0
            if(nex[i]&&i%len==0)
            {
                cout<<i<<" "<<i/len<<endl;
            }
        }
        cout<<endl;
        tt++;
    }
    
    
    
    return 0;
}