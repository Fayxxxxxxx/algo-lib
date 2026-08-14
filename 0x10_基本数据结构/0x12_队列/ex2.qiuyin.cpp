    #include<bits/stdc++.h>
    using namespace std;

    #define int long long
    #define endl '\n'

    signed main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);

        int n,m,q,u,v,t;
        cin >> n >> m >> q >> u >> v >> t;

        priority_queue<int> pq;

        for(int i=0;i<n;i++)
        {
            int x;
            cin >> x;
            pq.push(x);
        }

        int add=0;

        for(int i=0;i<m;i++)
        {
            int Max=pq.top()+add;
            pq.pop();

            if((i+1)%t==0)
                cout << Max << " ";

            int x1=Max*u/v;
            int x2=Max-x1;

            pq.push(x1-add-q);
            pq.push(x2-add-q);

            add+=q;
        }

        cout << endl;

        int cnt=0;

        while(!pq.empty())
        {
            int x=pq.top()+add;
            pq.pop();

            cnt++;

            if(cnt%t==0)
                cout << x << " ";
        }

        cout << endl;

        return 0;
    }
