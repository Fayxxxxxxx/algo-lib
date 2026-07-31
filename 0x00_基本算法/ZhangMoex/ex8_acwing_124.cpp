#include<bits/stdc++.h>
  using namespace std;

  #define int long long
  #define endl '\n'

  char arr[62]={'0','1','2','3','4','5','6','7','8','9','A','B'
  ,'C','D','E','F','G','H','I','J','K','L','M','N','O','P'
  ,'Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e'
  ,'f','g','h','i','j','k','l','m','n','o','p','q','r','s','t'
  ,'u','v','w','x','y','z'};

  vector<int> mul(vector<int>& nums, int x)
  {
      int t = 0;
      vector<int> c;
      for (int i = 0; i < nums.size() || t; i++)
      {
          if (i < nums.size()) t += nums[i] * x;
          c.push_back(t % 10);
          t /= 10;
      }
      return c;
  }

  vector<int> add(vector<int>& nums, int x)
  {
      for (int i = 0; x; i++)
      {
          if (i >= nums.size()) nums.push_back(0);
          x = nums[i] + x;
          nums[i] = x % 10;
          x /= 10;
      }
      return nums;
  }

  vector<int> div_by_base(vector<int>& nums, int x, int& remainder)
  {
      remainder = 0;
      vector<int> c;

      for (int i = nums.size() - 1; i >= 0; i--)
      {
          remainder = remainder * 10 + nums[i];
          c.push_back(remainder / x);
          remainder %= x;
      }
      reverse(c.begin(), c.end());
      while (c.size() > 1 && c.back() == 0) c.pop_back();

      return c;
  }

  bool is_zero(vector<int>& nums)
  {
      return nums.size() == 1 && nums[0] == 0;
  }

  vector<char> dec_to_base(vector<int>& nums, int base)
  {
      vector<int> temp = nums;
      vector<char> res;

      while (!is_zero(temp))
      {
          int remainder;
          temp = div_by_base(temp, base, remainder);
          res.push_back(arr[remainder]);
      }

      if (res.empty()) res.push_back('0');
      reverse(res.begin(), res.end());
      return res;
  }

  void solve()
  {
      int innum, outnum;
      cin >> innum >> outnum;

      string s;
      cin >> s;

      vector<int> nums = {0};

      for (int i = 0; i < s.size(); i++) 
      {
          int x = 0;
          if ('0' <= s[i] && s[i] <= '9')
              x = s[i] - '0';
          else if ('A' <= s[i] && s[i] <= 'Z')
              x = 10 + s[i] - 'A';
          else
              x = 36 + s[i] - 'a';

          nums = mul(nums, innum);
          nums = add(nums, x);
      }

      vector<char> res = dec_to_base(nums, outnum);

      cout << innum << " " << s << endl;
      cout << outnum << " ";
      for(char c : res) cout << c;
      cout << endl << endl;
  }

  signed main()
  {
      ios::sync_with_stdio(0);
      cin.tie(0);

      int t;
      cin >> t;

      while (t--) solve();

      return 0;
  }






  #include<bits/stdc++.h>
  using namespace std;

  #define int long long
  #define endl '\n'

  char arr[62]={'0','1','2','3','4','5','6','7','8','9','A','B'
  ,'C','D','E','F','G','H','I','J','K','L','M','N','O','P'
  ,'Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e'
  ,'f','g','h','i','j','k','l','m','n','o','p','q','r','s','t'
  ,'u','v','w','x','y','z'};

  
int div(vector<int>& nums, int pre, int base)
  {
      int remainder = 0;

      for (int i = nums.size() - 1; i >= 0; i--)
      {
          int cur = remainder * pre + nums[i];
         nums[i]=cur /base ;
          remainder =cur% base;
      }
      
      while (nums.size() > 1 && nums.back() == 0) nums.pop_back();

      return remainder;
  }

  bool is_zero(vector<int>& nums)
  {
      return (nums.size() == 1 && nums[0] == 0);
  }

  void solve()
  {
      int innum, outnum;
      cin >> innum >> outnum;

      string s;
      cin >> s;

      vector<int> nums;
      for (int i = s.size() - 1; i >= 0; i--)
      {
          int x = 0;
          if ('0' <= s[i] && s[i] <= '9')      x = s[i] - '0';
          else if ('A' <= s[i] && s[i] <= 'Z') x = s[i] - 'A' + 10;
          else                                  x = s[i] - 'a' + 36;
          nums.push_back(x);
      }

      vector<char> res;
      while(!is_zero(nums))
      {
        int remainder=div(nums,innum,outnum);
        res.push_back(arr[remainder]);
      }
      if(res.empty())res.push_back('0');
      reverse(res.begin(),res.end());

      cout << innum << " " << s << endl;
      cout << outnum << " ";
      for(char c : res) cout << c;
      cout << endl << endl;
  }

  signed main()
  {
      ios::sync_with_stdio(0);
      cin.tie(0);

      int t;
      cin >> t;

      while (t--) solve();

      return 0;
  }