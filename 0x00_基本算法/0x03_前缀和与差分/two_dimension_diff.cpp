#include <bits/stdc++.h>
using namespace std;

class TwoDimDiff {
private:
    int n, m;
    vector<vector<long long>> diff;  // 差分数组，1-based，尺寸 (n+2) x (m+2)

public:
    // 构造函数：传入矩阵行数 n 和列数 m
    TwoDimDiff(int n, int m) : n(n), m(m) {
        diff.assign(n + 2, vector<long long>(m + 2, 0));
    }

    // 步骤1：区间加操作 [x1..x2] [y1..y2] 全部加 val
    void add(int x1, int y1, int x2, int y2, long long val) {
        // 边界校验（可选，确保下标在 [1, n] 和 [1, m] 内）
        if (x1 > x2 || y1 > y2 || x1 < 1 || x2 > n || y1 < 1 || y2 > m) return;

        diff[x1][y1] += val;
        diff[x2 + 1][y1] -= val;
        diff[x1][y2 + 1] -= val;
        diff[x2 + 1][y2 + 1] += val;
    }

    // 步骤2：还原得到最终矩阵（原地修改 diff 为前缀和）
    vector<vector<long long>> getResult() {
        vector<vector<long long>> res(n + 1, vector<long long>(m + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // 二维前缀和递推公式
                diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
                res[i][j] = diff[i][j];
            }
        }
        return res;
    }

    // （可选）如果初始矩阵非零，需要先将初始值通过 add 逐个或按行加入
    // 更高效的方式：构建时传入初始矩阵，在构造函数中初始化差分
};

// ============ 使用示例 ============
int main() {
    int n = 5, m = 5;
    TwoDimDiff d(n, m);

    // 对子矩阵 (2,2) 到 (4,4) 全部 +10
    d.add(2, 2, 4, 4, 10);

    // 对子矩阵 (1,1) 到 (3,3) 全部 +5
    d.add(1, 1, 3, 3, 5);

    // 获取最终矩阵
    auto result = d.getResult();

    // 输出 1-based 结果
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}





diff[x1][y1]+=diff[x1-1][y1]+diff[x1][y1-1]-diff[x1-1][y1-1];
res[x1][y1]=diff[x1][y1];



//三分法 

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left=-1;
        int right=arr.size();
        while(right-left>2)
        {
            int lm=left+(right-left)/3;
            int rm=right-(right-left)/3;

            if(arr[lm]<arr[rm])
            {
                left=lm;
            }
            else
            {
                right=rm;
            }
        }
        return left+1;
    }
};