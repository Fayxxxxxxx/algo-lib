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



    #include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

priority_queue<int> pq;
queue<int> Left, Right;

int get_max()
{
    int a = pq.empty() ? LLONG_MIN : pq.top();
    int b = Left.empty() ? LLONG_MIN : Left.front();
    int c = Right.empty() ? LLONG_MIN : Right.front();

    if(a >= b && a >= c)
    {
        pq.pop();
        return a;
    }
    else if(b >= a && b >= c)
    {
        Left.pop();
        return b;
    }
    else
    {
        Right.pop();
        return c;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,q,u,v,t;
    cin>>n>>m>>q>>u>>v>>t;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        pq.push(x);
    }

    int add=0;

    for(int i=1;i<=m;i++)
    {
        // 取当前最大的“相对长度”
        int x=get_max();

        // 恢复真实长度
        x+=add;

        if(i%t==0)
        {
            cout<<x<<" ";
        }

        // 切成两段
        int x1=x*u/v;
        int x2=x-x1;

        // 旧蚯蚓统一 +q
        add+=q;

        // 新产生的两条不能享受本轮 +q
        Left.push(x1-add);
        Right.push(x2-add);
    }

    cout<<endl;

    // 此时剩余 n+m 条蚯蚓
    // 三个容器本身都有序，继续三路取最大
    int cnt=0;

    while(!pq.empty() || !Left.empty() || !Right.empty())
    {
        int x=get_max();

        // 恢复 m 秒后的真实长度
        x+=add;

        cnt++;

        if(cnt%t==0)
        {
            cout<<x<<" ";
        }
    }

    cout<<endl;

    return 0;
}
