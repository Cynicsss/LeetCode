/*
75. 颜色分类

给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

注意:
不能使用代码库中的排序函数来解决这道题。

示例:

输入: [2,0,2,1,1,0]
输出: [0,0,1,1,2,2]
进阶：

一个直观的解决方案是使用计数排序的两趟扫描算法。
首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
你能想出一个仅使用常数空间的一趟扫描算法吗？

思路1：两趟扫描，类似于冒泡排序，找到后面数组中最小的，移动到左极小处。 时间复杂度n2
代码：
*/

class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        if(nums.size() == 0) return;
        int n = nums.size();
        int min;
        for(int i = 0; i < n - 1; i++)
        {
            min = i;
            for(int j = i + 1; j < n; j++)
                if(nums[j] < nums[min]) min = j;
            swap(nums[min], nums[i]);
        }
    }
};

/*
思路2：因为正好只有三个数，可以用双指针
初始化0的最右边界：p0 = 0。在整个算法执行过程中 nums[idx < p0] = 0.

初始化2的最左边界 ：p2 = n - 1。在整个算法执行过程中 nums[idx > p2] = 2.

初始化当前考虑的元素序号 ：curr = 0.

While curr <= p2 :

若 nums[curr] = 0 ：交换第 curr个 和 第p0个 元素，并将指针都向右移。

若 nums[curr] = 2 ：交换第 curr个和第 p2个元素，并将 p2指针左移 。

若 nums[curr] = 1 ：将指针curr右移。

代码：
*/

class Solution {
  public:
  /*
  荷兰三色旗问题解
  */
  void sortColors(vector<int>& nums) {
    // 对于所有 idx < p0 : nums[idx < p0] = 0
    // curr 是当前考虑元素的下标
    int p0 = 0, curr = 0;
    // 对于所有 idx > p2 : nums[idx > p2] = 2
    int p2 = nums.size() - 1;

    while (curr <= p2) {
      if (nums[curr] == 0) {
        swap(nums[curr++], nums[p0++]);
      }
      else if (nums[curr] == 2) {
        swap(nums[curr], nums[p2--]);
      }
      else curr++;
    }
  }
};

