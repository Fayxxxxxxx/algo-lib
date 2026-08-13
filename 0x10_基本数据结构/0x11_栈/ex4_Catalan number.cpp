#include<bits/stdc++.h>
  using namespace std;

  #define int long long
  #define endl '\n'

  const int BASE = 10000;  // 压4位：每个元素存 [0,10000) 的数
//这里用到了压位的技巧
//只需将10 改为BASE即可 压4位 然后最后输出的时候 第一位直接输出
//后面的都设为4位 不足setfill('0')
//在这之前要setw(4) cout<<setw(4)<<setfill('0')<<ans[i];
  vector<int> mul_vector(vector<int>& a, vector<int>& b)
  {
      vector<int> c(a.size() + b.size());
      for(int i = 0; i < a.size(); i++)
          for(int j = 0; j < b.size(); j++)
              c[i + j] += a[i] * b[j];   // 最大 9999*9999≈1e8，longlong 安全

      int t = 0;
      for(int i = 0; i < c.size(); i++)
      {
          t += c[i];
          c[i] = t % BASE;
          t /= BASE;
      }
      while(c.size() > 1 && c.back() == 0) c.pop_back();
      return c;
  }

  vector<int> qpow(int p, int cnt)
  {
      vector<int> base;
      int t = p;
      while(t) { base.push_back(t % BASE); t /= BASE; }  // 按 10000 进制拆

      vector<int> res(1, 1);
      while(cnt)
      {
          if(cnt & 1) res = mul_vector(res, base);
          base = mul_vector(base, base);
          cnt >>= 1;
      }
      return res;
  }

  const int N = 120010;
  vector<int> primes(N);
  vector<bool> isprime(N, true);
  int cnt = 0;

  void init(int n)
  {
      isprime[0] = false;
      isprime[1] = false;
      for(int i = 2; i <= n; i++)
      {
          if(isprime[i]) primes[cnt++] = i;
          for(int j = 0; j < cnt; j++)
          {
              int x = primes[j] * i;
              if(x > n) break;
              isprime[x] = false;
              if(i % primes[j] == 0) break;
          }
      }
  }

  int get(int n, int p)
  {
      int res = 0;
      while(n) { res += n / p; n /= p; }
      return res;
  }

  signed main()
  {
      ios::sync_with_stdio(0);
      cin.tie(0);

      int n;
      cin >> n;
      init(2 * n);

      vector<int> cnt_p(cnt);
      for(int i = 0; i < cnt; i++)
      {
          int p = primes[i];
          cnt_p[i] = get(2 * n, p) - 2 * get(n, p);
      }

      int tmp = n + 1;
      for(int i = 0; i < cnt && primes[i] <= tmp; i++)
      {
          while(tmp % primes[i] == 0)
          {
              cnt_p[i]--;
              tmp /= primes[i];
          }
      }

      vector<int> ans(1, 1);
      for(int i = 0; i < cnt; i++)
      {
          if(cnt_p[i] > 0)
          {
              vector<int> power = qpow(primes[i], cnt_p[i]);
              ans = mul_vector(ans, power);
          }
      }

      // 输出：最高位正常打印，其余补 4 位前导零
      cout << ans.back();
      for(int i = ans.size() - 2; i >= 0; i--)
          cout << setw(4) << setfill('0') << ans[i];
      cout << endl;

      return 0;
  }