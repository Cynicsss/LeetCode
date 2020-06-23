/* 78.子集
题目描述：
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例：
```
输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
```

## 思路
采用递归，依次向vector中添加新元素。 (回溯法)

## 代码
*/
class Solution {
public:
    vector<vector<int>> get(vector<int> nums, vector<vector<int>> result, int cur, vector<int> temp)
    {
        if(cur == nums.size()) return result;
        for(int i = cur; i < nums.size(); i++)
        {
            temp.push_back(nums[i]);
            result.push_back(temp);
            cur++;
            result = get(nums, result, cur, temp);
            temp.pop_back();
        }
        return result;
    }
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> result;
        if(nums.size() == 0) return result;
        vector<int> temp;
        int cur = 0;
        result.push_back(temp);
        return get(nums, result, cur, temp);
    }
};
