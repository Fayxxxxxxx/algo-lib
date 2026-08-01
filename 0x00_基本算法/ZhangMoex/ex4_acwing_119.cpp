#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
const double INF=1e10;
const int N=200010;
struct dot
{
double x,y;
int type;
}nums[N],tmp[N];

bool cmp(dot&a,dot& b)
{
    return a.x<b.x;
}

double dist(dot& a,dot& b)
{
    if(a.type==b.type)return INF;
    double dx=a.x-b.x;
    double dy=a.y-b.y;

    return sqrt(dx*dx+dy*dy);

}
double dfs(int left,int right)
{
    if(right-left<=1)
    {
        return INF;
    }
    int mid=left+(right-left)/2;
    double min_x=nums[mid].x;
    double res=min(dfs(left,mid),dfs(mid,right));
    
    {
        int k=0,i=left,j=mid;
        while(i<mid&&j<right)
        {
            if(nums[i].y<=nums[j].y)tmp[k++]=nums[i++];
            else
            {
                tmp[k++]=nums[j++];
            }
        }
        while(i<mid)tmp[k++]=nums[i++];
        while(j<right)tmp[k++]=nums[j++];

        for(int p=0;p<k;p++)
        {
            nums[left+p]=tmp[p];
        }
    }
    int k=0;
    for(int i=left;i<right;i++)
    {
        if(nums[i].x>=min_x-res&&nums[i].x<=min_x+res)
        {
            tmp[k++]=nums[i];
        }
    }

    for(int i=0;i<k;i++)
    {
        for(int j=i-1;j>=0&&tmp[i].y-tmp[j].y<=res;j--)
        {
            res=min(res,dist(tmp[i],tmp[j]));
         }
        }
    return res;
}
void solve()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>nums[i].x>>nums[i].y;
        nums[i].type=0;
    }
    for(int i=n;i<2*n;i++)
    {
        cin>>nums[i].x>>nums[i].y;
        nums[i].type=1;
    }
    random_shuffle(nums, nums + 2 * n);
    sort(nums,nums+2*n,cmp);
    double ans=dfs(0,2*n);
    
    cout<<ios::fixed<<setprecision(3)<<ans<<endl;
}
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;

while(t--)
{
    solve();
}



    return 0;
}




//一直卡TLE

#include<bits/stdc++.h>
  using namespace std;

  #define int long long
  #define endl '\n'
  const double INF = 1e15;
  const double eps = 1e-9;
  const int N = 200010;
  double mind;

  struct dot {
      double x, y;
      int type;
  } nums[N], tmp[N];

  bool cmp(dot& a, dot& b) {
      return a.x < b.x;
  }

  double dist(dot& a, dot& b) {
      if (a.type == b.type) return INF;
      double dx = a.x - b.x;
      double dy = a.y - b.y;
      return sqrt(dx * dx + dy * dy);
  }

  double dfs(int left, int right) {
      if (right - left <= 1) return INF;

      int mid = left + (right - left) / 2;
      double min_x = nums[mid].x;
      double res = min(mind, min(dfs(left, mid), dfs(mid, right)));

      if (res < eps) return res;

      int k = 0, i = left, j = mid;
      while (i < mid && j < right) {
          if (nums[i].y <= nums[j].y) tmp[k++] = nums[i++];
          else                        tmp[k++] = nums[j++];
      }
      while (i < mid) tmp[k++] = nums[i++];
      while (j < right) tmp[k++] = nums[j++];
      for (int p = 0; p < k; p++) nums[left + p] = tmp[p];

      k = 0;
      for (i = left; i < right; i++)
          if (nums[i].x >= min_x - res && nums[i].x <= min_x + res)
              tmp[k++] = nums[i];

      for (i = 0; i < k; i++)
          for (j = i - 1; j >= 0 && tmp[i].y - tmp[j].y + eps <= res; j--)
              res = min(res, dist(tmp[i], tmp[j]));

      mind = min(mind, res);
      return res;
  }

  void solve() {
      int n; cin >> n;
      for (int i = 0; i < n; i++) {
          cin >> nums[i].x >> nums[i].y;
          nums[i].type = 0;
      }
      for (int i = n; i < 2 * n; i++) {
          cin >> nums[i].x >> nums[i].y;
          nums[i].type = 1;
      }

      random_shuffle(nums, nums + 2 * n);
      sort(nums, nums + 2 * n, cmp);

      int p0 = -1, p1 = -1;
      for (int i = 0; i < 2 * n; i++) {
          if (p0 == -1 && nums[i].type == 0) p0 = i;
          if (p1 == -1 && nums[i].type == 1) p1 = i;
          if (p0 != -1 && p1 != -1) break;
      }
      mind = dist(nums[p0], nums[p1]);

      double ans = dfs(0, 2 * n);
      cout << fixed << setprecision(3) << ans << endl;
  }

  signed main() {
      ios::sync_with_stdio(0);
      cin.tie(0);
      int t; cin >> t;
      while (t--) solve();
      return 0;
  }