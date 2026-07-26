        #include<bits/stdc++.h>
        using namespace std;
        
        #define int long long
        int n,m,t;
        vector<int> cols;
        vector<int> rows;

        int ave_col;
        int ave_row;

        int cal_col()
        {
        vector<int> prefix(m+1);

        for(int i=1;i<=m;i++)
        {
            prefix[i]=prefix[i-1]+cols[i]-ave_col;
        }

        sort(prefix.begin()+1,prefix.end());

        int ans=0;

        for(int i=1;i<=m;i++)
        {
            ans+=abs(prefix[i]-prefix[m/2+1]);
        }

        return ans;
        }


        int cal_row()
        {
        vector<int> prefix(n+1);

        for(int i=1;i<=n;i++)
        {
            prefix[i]=prefix[i-1]+rows[i]-ave_row;
        }

        sort(prefix.begin()+1,prefix.end());

        int ans=0;

        for(int i=1;i<=n;i++)
        {
            ans+=abs(prefix[i]-prefix[n/2+1]);
        }

        return ans;
        }
       signed main()
        {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);



        cin>>n>>m>>t;

        cols.resize(m+1);
        rows.resize(n+1);

        for(int i=0;i<t;i++)
        {
            int x,y;
            cin>>x>>y;

            rows[x]++;
            cols[y]++;
        }
        bool flag_row=!(t%n),flag_col=!(t%m);

        if(!flag_row&&!flag_col)
        {
            cout<<"impossible"<<endl;
            return 0;
        }
        else if(flag_row&&!flag_col)
        {
            cout<<"row"<<" ";
            ave_row=t/n;

            cout<<cal_row()<<endl;
        }
        else if(!flag_row&&flag_col)
        {
            cout<<"column"<<" ";
        ave_col=t/m;
        cout<<cal_col()<<endl;
        }
        else
        {
            cout<<"both"<<" ";
        ave_row=t/n;
        ave_col=t/m;

        cout<<cal_row()+cal_col()<<endl;
        }
            return 0;
        }