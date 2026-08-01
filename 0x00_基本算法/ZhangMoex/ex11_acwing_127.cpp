#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

struct mechine
{
 int len;
 int level;
};
struct task
{
 int x;
 int y;
};

bool cmp_mechine(mechine&a ,mechine&b)
{
    if(a.len!=b.len)
    {
        return a.len>b.len;
    }
    return a.level>b.level;
}

bool cmp_task(task&a, task&b)
{
    if(a.x!=b.x)
    {
       return a.x>b.x;
    }
    return a.y>b.y;
}
int n,m;
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n>>m;
vector<task> tasks(m);
vector<mechine> mechines(n);

for(int i=0;i<n;i++)
{
    cin>>mechines[i].len>>mechines[i].level;
}
for(int i=0;i<m;i++)
{
    cin>>tasks[i].x>>tasks[i].y;
}
sort(mechines.begin(),mechines.end(),cmp_mechine);
sort(tasks.begin(),tasks.end(),cmp_task);

int cnt[101]={0};
int j=0;
int num=0;
int sum=0;
for(int i=0;i<m;i++)
{
 int x=tasks[i].x;
 int y=tasks[i].y;
 //去找第一个满足的 这样level更大的留给y更大的任务
 while(j<n&&mechines[j].len>=x)
 {
 cnt[mechines[j].level]++;
 j++;
 }

 for(int k=y;k<=100;k++)
 {
    if(cnt[k])
    {
        cnt[k]--;
        num++;
        sum+=500*x+2*y;
        break;
    }
}
 
}
cout<<num<<" "<<sum<<endl;



    return 0;
}