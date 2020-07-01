/*

152. 乘积最大子数组  难度：中等
给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。



示例 1:

输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:

输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。


思路：

因为存在负负得正情况，只维护一个状态转移方程是不够的，所以此题需要维护两个状态转移方程，一个记录乘积最小值，一个记录乘积最大值，每个判断需要判断max，min与当前元素的大小。
时间复杂度和空间复杂度都为O(n)

*/

class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int len = nums.size();
        if(len == 0) return 0;
        vector<int> dp_max(len), dp_min(len);
        dp_max[0] = nums[0];
        dp_min[0] = nums[0];
        for(int i = 1; i < len; i++)
        {
            dp_max[i] = max(nums[i], max(dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]));
            dp_min[i] = min(nums[i], min(dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]));
        }
        int Max = dp_max[0];
        for(int i = 0; i < len; i++)
            Max = max(Max, dp_max[i]);
        return Max;
    }
};

/*

优化空间复杂度：

只用两个变量来维护状态，同时记录当前最大值 最后返回最大值即可

*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxF = nums[0], minF = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int mx = maxF, mn = minF;
            maxF = max(mx * nums[i], max(nums[i], mn * nums[i]));
            minF = min(mn * nums[i], min(nums[i], mx * nums[i]));
            ans = max(maxF, ans);
        }
        return ans;
    }
};
