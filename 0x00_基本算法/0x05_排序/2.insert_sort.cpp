// 1.3 插入排序 Insertion Sort
// 思想：像打牌时整理手牌——每次拿一张新牌，插入到已排序部分的正确位置。这是 O(n²) 中最实用的排序。
// ⏱ 时间复杂度：O(n²)  最好 O(n)（已有序）  空间 O(1)  稳定
// 标准版：
// void insertionSort(int a[], int n) {
//     for (int i = 1; i < n; i++) {
//         int key = a[i];                       // 当前要插入的牌
//         int j = i - 1;
//         while (j >= 0 && a[j] > key) {        // 比 key 大的往后移
//             a[j + 1] = a[j];
//             j--;
//         }
//         a[j + 1] = key;                       // 插入正确位置
//     }
// }
// 💡 插入排序在小规模数据（n < 50）和"基本有序"的数组上极快。快速排序递归到底层时，常切换到插入排序。
// ────────────────────────────────────────────────────────────
// 二、进阶排序（O(n log n) 级别）
// 这四种是竞赛和面试的核心。归并、快速、堆排序三座大山，必须能 5 分钟内手写。
// 2.1 希尔排序 Shell Sort
// 思想：插入排序的升级版——先"大步长"跳着排，逐步缩小步长，最后做一次标准插入排序。大步长阶段让元素快速逼近目标位置。
// ⏱ 时间复杂度：≈O(n¹·³)（经验值）  最坏 O(n²)  空间 O(1)  不稳定
// void shellSort(int a[], int n) {
//     // gap 从 n/2 开始，每次折半
//     for (int gap = n / 2; gap > 0; gap /= 2)
//         for (int i = gap; i < n; i++) {       // 对每个子序列做插入排序
//             int key = a[i];
//             int j = i;
//             while (j >= gap && a[j - gap] > key) {
//                 a[j] = a[j - gap];
//                 j -= gap;
//             }
//             a[j] = key;
//         }
// }

void insert_sort(vector<int>&nums)
{
    for(int i=1;i<n;i++)
    {
        int key=nums[i];
        int j=i-1;

        while(j>=0&&nums[i]>=nums[j])
        {
            nums[j+1]=nums[j];
            j--;
        }

        nums[j]=key;
    }
}


void Shell_sort(vector<int>& nums)
{
    for(int gap=n/2;gap>0;gap/=2)
    {
      for(int i=gap;i<n;i++)
      {
        int key=nums[i];
        int j=i;

        while(j>=gap&&nums[j-gap]>=key)
        {
           nums[j]=nums[j-gap];
           j-=gap;
        }
        nums[j]=key;
      }
    }
}