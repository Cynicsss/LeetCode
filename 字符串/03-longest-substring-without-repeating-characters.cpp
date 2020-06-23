/*
3. 无重复字符的最长子串
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。



思路1：滑动窗口/双指针

设立左指针a和右指针b
b指针向右侧伸缩{
    对每个A[b]判断是否在之前的数组出现过；
        如果出现，指针a指向出现过的位置的下一个位置；
    更新右指针和最大长度；
}

*/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        //s[start,end) 前面包含 后面不包含
        int start(0), end(0), length(0), result(0);
        int sSize = int(s.size());
        while (end < sSize)
        {
            char tmpChar = s[end];
            for (int index = start; index < end; index++)
            {
                if (tmpChar == s[index])
                {
                    start = index + 1;
                    length = end - start;
                    break;
                }
            }

            end++;
            length++;
            result = max(result, length);
        }
        return result;
    }
};

/*
思路2：
用hashmap优化时间
利用hashmap存出现过的字符，这样优化时间到O(n)

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int l = 0, r = 0, length = 0, result = 0;
        unordered_map<char, int> hash;
        while(r < s.size())
        {
            char temp = s[r];
            if(hash.find(temp) != hash.end() && hash[temp] >= l)
            {
                l = hash[temp] + 1;
                length = r - l;
            }
            hash[temp] = r;
            length++;
            r++;
            result = max(length, result);
        }
        return result;
    }
};
