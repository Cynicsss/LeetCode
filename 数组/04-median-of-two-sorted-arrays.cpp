/*
4. 寻找两个正序数组的中位数   难度：困难
给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。

请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。



示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5



思路：
方法一：二分查找
给定两个有序数组，要求找到两个有序数组的中位数，最直观的思路有以下两种：

使用归并的方式，合并两个有序数组，得到一个大的有序数组。大的有序数组的中间位置的元素，即为中位数。

不需要合并两个有序数组，只要找到中位数的位置即可。由于两个数组的长度已知，因此中位数对应的两个数组的下标之和也是已知的。维护两个指针，初始时分别指向两个数组的下标 00 的位置，每次将指向较小值的指针后移一位（如果一个指针已经到达数组末尾，则只需要移动另一个数组的指针），直到到达中位数的位置。

假设两个有序数组的长度分别为 mm 和 nn，上述两种思路的复杂度如何？

第一种思路的时间复杂度是 O(m+n)O(m+n)，空间复杂度是 O(m+n)O(m+n)。第二种思路虽然可以将空间复杂度降到 O(1)O(1)，但是时间复杂度仍是 O(m+n)O(m+n)。题目要求时间复杂度是 O(\log(m+n))O(log(m+n))，因此上述两种思路都不满足题目要求的时间复杂度。

如何把时间复杂度降低到 O(\log(m+n))O(log(m+n)) 呢？如果对时间复杂度的要求有 \loglog，通常都需要用到二分查找，这道题也可以通过二分查找实现。

根据中位数的定义，当 m+nm+n 是奇数时，中位数是两个有序数组中的第 (m+n)/2(m+n)/2 个元素，当 m+nm+n 是偶数时，中位数是两个有序数组中的第 (m+n)/2(m+n)/2 个元素和第 (m+n)/2+1(m+n)/2+1 个元素的平均值。因此，这道题可以转化成寻找两个有序数组中的第 kk 小的数，其中 kk 为 (m+n)/2(m+n)/2 或 (m+n)/2+1(m+n)/2+1。

假设两个有序数组分别是 \text{A}A 和 \text{B}B。要找到第 kk 个元素，我们可以比较 \text{A}[k/2-1]A[k/2−1] 和 \text{B}[k/2-1]B[k/2−1]，其中 // 表示整数除法。由于 \text{A}[k/2-1]A[k/2−1] 和 \text{B}[k/2-1]B[k/2−1] 的前面分别有 \text{A}[0\,..\,k/2-2]A[0..k/2−2] 和 \text{B}[0\,..\,k/2-2]B[0..k/2−2]，即 k/2-1k/2−1 个元素，对于 \text{A}[k/2-1]A[k/2−1] 和 \text{B}[k/2-1]B[k/2−1] 中的较小值，最多只会有 (k/2-1)+(k/2-1) \leq k/2-2(k/2−1)+(k/2−1)≤k/2−2 个元素比它小，那么它就不能是第 kk 小的数了。

因此我们可以归纳出三种情况：

如果 \text{A}[k/2-1] < \text{B}[k/2-1]A[k/2−1]<B[k/2−1]，则比 \text{A}[k/2-1]A[k/2−1] 小的数最多只有 \text{A}A 的前 k/2-1k/2−1 个数和 \text{B}B 的前 k/2-1k/2−1 个数，即比 \text{A}[k/2-1]A[k/2−1] 小的数最多只有 k-2k−2 个，因此 \text{A}[k/2-1]A[k/2−1] 不可能是第 kk 个数，\text{A}[0]A[0] 到 \text{A}[k/2-1]A[k/2−1] 也都不可能是第 kk 个数，可以全部排除。

如果 \text{A}[k/2-1] > \text{B}[k/2-1]A[k/2−1]>B[k/2−1]，则可以排除 \text{B}[0]B[0] 到 \text{B}[k/2-1]B[k/2−1]。

如果 \text{A}[k/2-1] = \text{B}[k/2-1]A[k/2−1]=B[k/2−1]，则可以归入第一种情况处理。


*/
class Solution {
public:
    double findK(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int len1 = nums1.size(), len2 = nums2.size();
        int index1 = 0, index2 = 0;
        while(1)
        {
            //边界
            if(index1 == len1) return nums2[index2 + k - 1];
            if(index2 == len2) return nums1[index1 + k - 1];
            if(k == 1)
                return min(nums1[index1], nums2[index2]);

            //正常
            int newIndex1 = min(index1 + k / 2 - 1, len1 - 1);
            int newIndex2 = min(index2 + k / 2 - 1, len2 - 1);
            int pivot1 = nums1[newIndex1], pivot2 = nums2[newIndex2];
            if(pivot1 <= pivot2)
            {
                k = k - (newIndex1 - index1 + 1);
                index1 = newIndex1 + 1;
            }
            else
            {
                k = k - (newIndex2 - index2 + 1);
                index2 = newIndex2 + 1;
            }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int total_len = nums1.size() + nums2.size();
        if(total_len % 2 == 1) return findK(nums1, nums2, (total_len+1) / 2);
        else
            return ((findK(nums1, nums2, total_len / 2) + findK(nums1, nums2, total_len / 2 + 1)) / 2.0);
    }
};

