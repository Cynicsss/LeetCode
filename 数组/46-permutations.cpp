/*
46. 全排列 难度：中等
给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]


思路：
回溯法，要掌握回溯法模板，找到需求巧妙设计递归
此题要明确，因为是无重复数组，所以只要其中元素位置有所变化，那必是不同的排列，所以不用担心重复问题。

*/

class Solution {
public:

    void perm_tool(vector<vector<int>> &result, vector<int> &out, int cur, int length)
    {
        if(cur == length)
        {
            result.push_back(out);
            return;
        }
        for(int i = cur; i < length; i++)
        {
            swap(out[i], out[cur]);
            perm_tool(result, out, cur+1, length);
            swap(out[i], out[cur]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> result;
        perm_tool(result, nums, 0, nums.size());
        return result;
    }
};
