    #include<bits/stdc++.h>
    using namespace std;

    #define endl '\n'
    using ll=long long;
    using pii=pair<int,int>;
    using pll=pair<ll,ll>;
    using vi=vector<int>;
    using vll=vector<ll>;

    int main()
    {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s1,s2;
    cin>>s1>>s2;
    s2=s2+s2;
    int n=s1.size();
    int m=s2.size();
    s1=" "+s1;
    s2=" "+s2;
    vector<int> ne(n+1);
    for(int i=2,j=0;i<=n;i++)
    {
        while(j&&s1[i]!=s1[j+1])
        {
            j=ne[j];
        }
        
        if(s1[i]==s1[j+1])
        {
            j++;
        }
        ne[i]=j;
    }
    bool flag=false;
    for(int i=1,j=0;i<=m;i++)
    {
        while(j&&s2[i]!=s1[j+1])
        {
            j=ne[j];
        }

        if(s2[i]==s1[j+1])
        {
            j++;
        }

        if(j==n)
        {
        flag=true;
        break;
        }
    }
    if(!flag)
    {
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    s2.erase(s2.begin());
    int i=0;
    int j=1;
    int ans;
    while(i<m&&j<m)
    {
        int k=0;
        while(k<n&&s2[i+k]==s2[j+k])
        {
            k++;
        }
        if(s2[i+k]>s2[j+k])
        {
            i=i+k+1;
        }
        else
        {
            j=j+k+1;
        }

        if(i==j)
        {
            j++;
        }
    }
    ans=min(i,j);
    for(int k=ans;k<ans+n;k++)
    {
    cout<<s2[k];
    }
    cout<<endl;

        return 0;
    }