    // //错误二分的写法 会超时
    
    // #include<bits/stdc++.h>
    // using namespace std;


    // bool check(int left,int right,vector<int> nums,int t,int m)
    // {
    //     sort(nums.begin()+left,nums.begin()+right);
        
    //     int n=min((right-left)/2,m);
        
    //     int ans=0;

    //     for(int i=0;i<n;i++)
    //     {
    //     ans+=((nums[right-i-1]-nums[left+i])*(nums[right-i-1]-nums[left+i]));
    //     if(ans>t)
    //     {
    //         return false;
    //     }
    //     }
    //     return true;
    // }
    // void solve()
    // {
    //     int n,m,t;

    //     cin>>n>>m>>t;

    //     vector<int> nums(n);

    //     for(int i=0;i<n;i++)
    //     {
    //         cin>>nums[i];
    //     }

    //     int l=0;
        
    //     int cnt=0;

    //     while(l!=n)
    //     {
    //     int left=l;//这里是l 不是一  如果不为1 那么l=0的时候 就没法找到一个合适的值
    //     //因为0没有放进去排序
    //     int right=nums.size();

    //     while(right-left>1)
    //     {
    //         int mid=left+(right-left)/2;

    //         check(l,mid+1,nums,t,m)?left=mid:right=mid;
    //     }
        
    //     l=left+1;
    //     cnt++;
    //     }

    //     cout<<cnt<<endl;


    // }
    // int main()
    // {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    // int k;
    // cin>>k;

    // while(k--)
    // {
    //     solve();
    // }


    //     return 0;
    // }

    //倍增写法


#include <bits/stdc++.h>
  using namespace std;
  #define int long long

  const int N = 500005;
  int n, m, t;
  int a[N];           // 原数组
  int sorted[N];      // 已确认合法段的排序结果
  int tmp[N];         // 归并临时数组
  int new_seg[N];     // 新扩展段的排序结果

  // 校验 [l, r) 的校验值是否 ≤t（归并结果在 tmp 中）
  bool check_val(int len) {
      int pairs = min(m, len / 2);
      int val = 0;
      for (int i = 0; i < pairs; i++) {
          int diff = tmp[len - 1 - i] - tmp[i];
          val += diff * diff;
          if (val > t) return false;
      }
      return true;
  }

  // 尝试扩展：已排序的 [l, r) + 新增 [r, r+p)
  bool extend(int l, int r, int p) {
      // 1. 把新段 [r, r+p) 拷贝出来排序
      for (int i = r; i < r + p; i++)
          new_seg[i - r] = a[i];
      sort(new_seg, new_seg + p);

      // 2. 归并：已排序的 [l, r) 和 新段 →tmp
      int i = l, j = 0, k = 0;
      while (i < r && j < p) {
          if (sorted[i] <= new_seg[j])
              tmp[k++] = sorted[i++];
          else
              tmp[k++] = new_seg[j++];
      }
      while (i < r) tmp[k++] = sorted[i++];
      while (j < p) tmp[k++] = new_seg[j++];

      // 3. 校验
      if (check_val(r - l + p)) {
          // 4. 通过了！把 tmp 写回 sorted，为下一轮做准备
          for (int i = 0; i < r - l + p; i++)
              sorted[l + i] = tmp[i];
          return true;
      }
      return false;
  }

  void solve() {
      cin >> n >> m >> t;
      for (int i = 0; i < n; i++) cin >> a[i];

      int l = 0, cnt = 0;
      while (l < n) {
          int r = l, p = 1;
          sorted[l] = a[l];  // 第一个元素总是合法的

          while (p) {
              if (r + p <= n && extend(l, r, p)) {
                  r += p;
                  p <<= 1;  // 加倍
              } else {
                  p >>= 1;  // 减半
              }
          }
          l = r;
          cnt++;
      }
      cout << cnt << '\n';
  }

  signed main() {
      ios::sync_with_stdio(0);
      cin.tie(0);
      int k; cin >> k;
      while (k--) solve();
      return 0;
  }