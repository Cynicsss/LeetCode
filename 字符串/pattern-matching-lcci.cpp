/*

面试题 16.18. 模式匹配  难度:中等 个人感觉困难
你有两个字符串，即pattern和value。 pattern字符串由字母"a"和"b"组成，用于描述字符串中的模式。例如，字符串"catcatgocatgo"匹配模式"aabab"（其中"cat"是"a"，"go"是"b"），该字符串也匹配像"a"、"ab"和"b"这样的模式。但需注意"a"和"b"不能同时表示相同的字符串。编写一个方法判断value字符串是否匹配pattern字符串。

示例 1：

输入： pattern = "abba", value = "dogcatcatdog"
输出： true
示例 2：

输入： pattern = "abba", value = "dogcatcatfish"
输出： false
示例 3：

输入： pattern = "aaaa", value = "dogcatcatdog"
输出： false
示例 4：

输入： pattern = "abba", value = "dogdogdogdog"
输出： true
解释： "a"="dogdog",b=""，反之也符合规则
提示：

1 <= len(pattern) <= 1000
0 <= len(value) <= 1000
你可以假设pattern只包含字母"a"和"b"，value仅包含小写字母。



思路1：
枚举
官方的思路，看到怀疑人生

https://leetcode-cn.com/problems/pattern-matching-lcci/solution/mo-shi-pi-pei-by-leetcode-solution/


*/


class Solution {
public:
    bool patternMatching(string pattern, string value) {
        int count_a = 0, count_b = 0;
        for (char ch: pattern) {
            if (ch == 'a') {
                ++count_a;
            } else {
                ++count_b;
            }
        }
        if (count_a < count_b) {
            swap(count_a, count_b);
            for (char& ch: pattern) {
                ch = (ch == 'a' ? 'b' : 'a');
            }
        }
        if (value.empty()) {
            return count_b == 0;
        }
        if (pattern.empty()) {
            return false;
        }
        for (int len_a = 0; count_a * len_a <= value.size(); ++len_a) {
            int rest = value.size() - count_a * len_a;
            if ((count_b == 0 && rest == 0) || (count_b != 0 && rest % count_b == 0)) {
                int len_b = (count_b == 0 ? 0 : rest / count_b);
                int pos = 0;
                bool correct = true;
                string value_a, value_b;
                for (char ch: pattern) {
                    if (ch == 'a') {
                        string sub = value.substr(pos, len_a);
                        if (!value_a.size()) {
                            value_a = move(sub);
                        } else if (value_a != sub) {
                            correct = false;
                            break;
                        }
                        pos += len_a;
                    } else {
                        string sub = value.substr(pos, len_b);
                        if (!value_b.size()) {
                            value_b = move(sub);
                        } else if (value_b != sub) {
                            correct = false;
                            break;
                        }
                        pos += len_b;
                    }
                }
                if (correct && value_a != value_b) {
                    return true;
                }
            }
        }
        return false;
    }
};


/*
思路2：
参考一个同学的题解，清晰易懂 非常牛掰

*/

class Solution {
public:
    bool patternMatching(string pattern, string value)
    {
        int pl = pattern.size(), vl = value.size();
        if(pl == 0 && vl == 0) return true;
        else if(pl == 0) return false;

        int anum = 0, bnum = 0;
        for(int i = 0; i < pl; i++)
        {
            if(pattern[i] == 'a') anum++;
            else bnum++;
        }
        int amax = anum == 0 ? 0 : vl / anum;
        int bmax = bnum == 0 ? 0 : vl / bnum;

        for(int al = 0; al <= amax; al++)
        {
            for(int bl = 0; bl <= bmax; bl++)
            {
                if((al * anum + bl * bnum) == vl)
                {
                    string A = "@", B = "@";
                    int index = 0;
                    for(int i = 0; i < pl; i++)
                    {
                        if(pattern[i] == 'a')
                        {
                            if(A == "@") A = value.substr(index, al);
                            else if(value.substr(index, al) != A) break;
                            index += al;
                        }
                        else if(pattern[i] == 'b')
                        {
                            if(B == "@") B = value.substr(index, bl);
                            else if(value.substr(index, bl) != B) break;
                            index += bl;
                        }
                    }
                    if(index == vl && A != B) return true;
                }
            }
        }
        return false;
    }
};







