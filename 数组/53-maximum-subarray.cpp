/*
53. 最大子序和  难度：简单
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。



思路1：暴力法
尝试了，超时


思路2：动态规划
dp[i]表示nums中以nums[i]结尾的最大子序和
dp[i] = max(dp[i - 1] + nums[i], nums[i]);
dp[i]时当前数字，要么是与前面的最大子序和的和，要么是自身

*/
class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int MAX = INT_MIN;
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int result = dp[0];
        for(int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            result = max(result, dp[i]);
        }
        return result;
    }
};

