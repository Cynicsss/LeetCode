/*
88. 合并两个有序数组  难度：简单
给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。



说明:

初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。


示例:

输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]


思路1：
归并排序
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        vector<int> temp;
        for(int i = 0; i < m; i++)
            temp.push_back(nums1[i]);
        int l1 = 0, l2 = 0, k = 0;
        while(l1 < m && l2 < n)
        {
            if(temp[l1] <= nums2[l2])
                nums1[k++] = temp[l1++];
            else if(temp[l1] > nums2[l2])
                nums1[k++] = nums2[l2++];
        }
        while(l1 < m)
            nums1[k++] = temp[l1++];
        while(l2 < n)
            nums1[k++] = nums2[l2++];
    }
};


/*
思路2：

从后往前倒序比较两个数组大小，选取大的填充到nums1的尾部，从后往前可以避免移动数组元素。
如果nums2处理完了，num1剩余元素是不需要处理的，所以遍历的时候只需要遍历nums2，但是比较大小之前要判断num1是否处理完，避免数组越界。

*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = m + n - 1;
        while (n) {
            if (m == 0) {
                nums1[last--] = nums2[--n];
            } else if (nums2[n-1] > nums1[m-1]) {
                nums1[last--] = nums2[--n];
            } else {
                nums1[last--] = nums1[--m];
            }
        }
    }
};
