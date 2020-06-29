/*
14. 最长公共前缀  难度：简单
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。


思路1：

最简单的思路就是暴力穷举遍历，时间也通过了   时间复杂度为O(mn)
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string common_pref;
        if(strs.size() == 0) return common_pref;
        if(strs.size() == 1) return strs[0];
        common_pref = strs[0];
        for(int i = 1; i < strs.size(); i++)
        {
            string temp;
            int j = 0;
            while(j < common_pref.size() && j < strs[i].size())
            {
                if(common_pref[j] == strs[i][j])
                {
                    temp += common_pref[j];
                    j++;
                }
                else if(j == 0 && common_pref[j] != strs[i][j]) return "";
                else if(common_pref[j] != strs[i][j])
                    break;
            }
            common_pref = temp;
        }
        return common_pref;
    }
};



/*
思路2
纵向扫描

另一种方法是纵向扫描。纵向扫描时，从前往后遍历所有字符串的每一列，比较相同列上的字符是否相同，如果相同则继续对下一列进行比较，如果不相同则当前列不再属于公共前缀，当前列之前的部分为最长公共前缀。

时间复杂度同样为O(mn)

*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (!strs.size())
            return "";
        int length = strs[0].size();
        int count = strs.size();
        for (int i = 0; i < length; ++i) {
            char c = strs[0][i];
            for (int j = 1; j < count; ++j) {
                if (i == strs[j].size() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

/*
思路3
方法三：分治
https://leetcode-cn.com/problems/longest-common-prefix/solution/zui-chang-gong-gong-qian-zhui-by-leetcode-solution/
时间复杂度:O(mn)
空间复杂度:O(mlogn)

*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) {
            return "";
        }
        else {
            return longestCommonPrefix(strs, 0, strs.size() - 1);
        }
    }

    string longestCommonPrefix(const vector<string>& strs, int start, int end) {
        if (start == end) {
            return strs[start];
        }
        else {
            int mid = (start + end) / 2;
            string lcpLeft = longestCommonPrefix(strs, start, mid);
            string lcpRight = longestCommonPrefix(strs, mid + 1, end);
            return commonPrefix(lcpLeft, lcpRight);
        }
    }

    string commonPrefix(const string& lcpLeft, const string& lcpRight) {
        int minLength = min(lcpLeft.size(), lcpRight.size());
        for (int i = 0; i < minLength; ++i) {
            if (lcpLeft[i] != lcpRight[i]) {
                return lcpLeft.substr(0, i);
            }
        }
        return lcpLeft.substr(0, minLength);
    }
};



