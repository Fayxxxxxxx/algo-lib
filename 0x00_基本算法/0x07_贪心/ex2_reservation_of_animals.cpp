//错误的写法

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
struct cow
{
 int left;
 int right;
 int id=1;
};

bool cmp(cow& a,cow& b)
{
    if(a.left!=b.left)
    {
        return a.left<=b.left;
    }

    return a.right<=b.right;
}
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);



int n;
cin>>n;

vector<cow> cows(n);

for(int i=0;i<n;i++)
{
    cin>>cows[i].left>>cows[i].right;
}
sort(cows.begin(),cows.end(),cmp);

int left=cows[0].left;
int right=cows[0].right;

int cnt=0;

vector<int> nums;
unordered_map<int,int> record;

for(int i=0;i<n;i++)
{
   int r_left=cows[i].left;
   int r_right=cows[i].right;

   if(r_left<=right)
   {
     if(i==0)
     {
        nums.push_back(cnt+cows[i].id);

     }
     else
     {
        nums.push_back(cnt+cows[i-1].id);
     }
     cnt++;

     left=min(left,r_left);
     right=max(right,r_right);
   }
   else
   {
    cnt=1;
    nums.push_back(cows[i].id);
    left=r_left;
    right=r_right;
   }
}
vector<int> total=nums;
total.erase(unique(total.begin(),total.end()),total.end());

cout<<total.size()<<endl;
for(int x:nums)
{
    cout<<x<<endl;
}


    return 0;
}




#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

struct cow
{
    int left;
    int right;
};

struct range
{
 int right;
 int id;
};

struct tmp
{
 bool operator()(range& a,range& b)
 {
    return a.right>=b.right;
 }
};

bool cmp(cow&a,cow&b)
{
    if(a.left!=b.left)
    {
        return a.left<=b.left;
    }
    return a.right<=b.right;
}
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

int n;
cin>>n;

vector<cow> cows(n);

for(int i=0;i<n;i++)
{ 
    cin>>cows[i].left>>cows[i].right;
}

priority_queue<range,vector<range>,tmp) pq;

vector<int> nums;
sort(cows.begin(),cows.end(),cmp);

for(int i=0;i<n;i++)
{
    if(pq.empty())
    {
        pq.push({cows[i].right,1});
        nums.push_back(1);
    }
    else
    {
        if(cows[i].left<=pq.top().right)
        {
            pq.push({cows[i].right,pq.top().id+1});
            nums.push_back(id+1);
        }
        else
        {
            int d=pq.top().id;
            pq.pop();
            pq.push({cows[i].right,d});
        }
    }
}

cout<<pq.size()<<endl;

for(int x:nums)
{
    cout<<x<<endl;
}
    return 0;
}


//正确的写法 nums不能push_back 而是给cow也一个id让他按照顺序输出

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

struct cow
{
    int left;
    int right;
    int id;
};

struct range
{
 int right;
 int id;
};

struct tmp
{
 bool operator()(range& a,range& b)
 {
    return a.right>=b.right;
 }
};

bool cmp(cow&a,cow&b)
{
    if(a.left!=b.left)
    {
        return a.left<=b.left;
    }
    return a.right<=b.right;
}
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

int n;
cin>>n;

vector<cow> cows(n);

for(int i=0;i<n;i++)
{
    cin>>cows[i].left>>cows[i].right;
    cows[i].id=i;
}

priority_queue<range,vector<range>,tmp> pq;

vector<int> nums(n);

sort(cows.begin(),cows.end(),cmp);
int nex_id=1;

for(int i=0;i<n;i++)
{
    if(pq.empty())
    {
        pq.push({cows[i].right,1});
        nums[cows[i].id]=1;
        nex_id++;
    }
    else
    {
        if(cows[i].left<=pq.top().right)
        {
            nums[cows[i].id]=nex_id;
            pq.push({cows[i].right,nex_id});
            nex_id++;
        }
        else
        {
            int d=pq.top().id;
            pq.pop();
            pq.push({cows[i].right,d});
            nums[cows[i].id]=d;
        }
    }
}

cout<<pq.size()<<endl;

for(int x:nums)
{
    cout<<x<<endl;
}
    return 0;
}

