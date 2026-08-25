        #include<bits/stdc++.h>
        using namespace std;

        #define endl '\n'
        using ll=long long;
        using pii=pair<int,int>;
        using pll=pair<ll,ll>;
        using vi=vector<int>;
        using vll=vector<ll>;
        using ull=unsigned long long;
        vector<ull> h1;//横向归横向
        vector<ull> p;
        vector<ull> h2;//纵向归纵向
        vector<ull> p2;
        const int P=131;
        const int P2=13331;
        ull get_num1(int l,int r)
        {
            return h1[r]-h1[l-1]*p[r-l+1];
        }
        ull get_num2(int l,int r)
        {
            return h2[r]-h2[l-1]*p2[r-l+1];
        }
        int main()
        {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int n,m,a,b;
        cin>>n>>m>>a>>b;
        vector<string> nums(n+1);
        for(int i=1;i<=n;i++)
        {
            cin>>nums[i];
        }
        int q;
        cin>>q;
        if(a>n||b>m)
    {
        while(q--)
        {
            string s;

            for(int i=1;i<=a;i++)
                cin>>s;

            cout<<0<<endl;
        }

        return 0;
    }
        int Max_w=max(a,b);
        p.resize(Max_w+1);
        p[0]=1;
        p2.resize(Max_w+1);
        p2[0]=1;
        for(int i=1;i<=Max_w;i++)
        {
            p[i]=p[i-1]*P;
        }
        for(int i=1;i<=Max_w;i++)
        {
            p2[i]=p2[i-1]*P2;
        }   
        vector<vector<ull>> tmp(n+1,vector<ull>(m-b+2));
        for(int i=1;i<=n;i++)
        {
            h1.assign(m+1,0);
            for(int j=1;j<=m;j++)
            {
                h1[j]=h1[j-1]*P+(nums[i][j-1]-'0'+1);
            }

            for(int j=1;j<=m-b+1;j++)
            {
                tmp[i][j]=get_num1(j,j+b-1);
            }
        }
        //tmp 是个高为n 长为m-b+1的横向压缩过的数组 然后进行纵向的压缩
        vector<ull> res;
        for(int i=1;i<=m-b+1;i++)
        {
            h2.assign(n+1,0);
            for(int j=1;j<=n;j++)
            {
                h2[j]=h2[j-1]*P2+(tmp[j][i]);
            }

            for(int j=1;j<=n-a+1;j++)
            {
                res.push_back(get_num2(j,j+a-1));
            }
        }
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        while(q--){
        ull H=0;

        for(int i=1;i<=a;i++)
        {
            ull A=0;
            string s;
            cin>>s;
            for(char x:s)
            {
            A=A*P+(x-'0'+1);
            }

            H=H*P2+A;
        }
        int left=-1;
        int right=res.size();
        while(right-left>1)
        {
            int mid=left+(right-left)/2;

            if(res[mid]<H)
            {
                left=mid;
            }
            else
            {
                right=mid;
            }
        }

        if(right<res.size()&&res[right]==H)
        {
            cout<<1<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
        }

            return 0;
        }