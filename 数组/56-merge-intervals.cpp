/* 56.合并区间
题目描述：
给出一个区间集合，请合并所有重叠的区间。
示例1:
```
输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
```

示例2:
```
输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
```

## 思路
首先对区间以首元素进行排序，排好序后区间之间便是连续的就好判断了：

判断新区间的首元素是否大于旧区间的右极限，如果大于，则直接将此区间加入到结果vector中，如果小于，判断新区间右值与旧区间右值大小，大的话更新旧区间右值为新区间右值，小的话直接跳过。

## 代码
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>> result;
        if(intervals.size() == 0) return result;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){return a[0] < b[0];});
        for(int i = 0; i < intervals.size(); i++)
        {
            if(result.size() == 0)
                result.push_back(intervals[i]);
            else
            {
                if(intervals[i][0] > result[result.size() - 1][1]) result.push_back(intervals[i]);
                else
                {
                    if(intervals[i][1] <= result[result.size() - 1][1]) continue;
                    else
                        result[result.size() - 1][1] = intervals[i][1];
                }
            }
        }
        return result;
    }
};
