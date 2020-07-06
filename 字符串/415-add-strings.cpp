/*

415. 字符串相加
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

注意：

num1 和num2 的长度都小于 5100.
num1 和num2 都只包含数字 0-9.
num1 和num2 都不包含任何前导零。
你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。




思路1：
正常相加，遍历两个字符串，从末位相加，使用一个变量记录进位。
插入数字时在结果的开头插入。

*/

class Solution {
public:
    string addStrings(string num1, string num2)
    {
        string result;
        int len1 = num1.size() - 1;
        int len2 = num2.size() - 1;

        int forward = 0;
        int sum = 0;
        while(len1 >= 0 && len2 >= 0)
        {
            sum = (int)(num1[len1] - '0') + (int)(num2[len2] - '0') + forward;
            if(sum >= 10)
            {
                sum -= 10;
                forward = 1;
            }
            else forward = 0;
            result.insert(0, to_string(sum));
            len1--;
            len2--;
        }

        while(len1 >= 0)
        {
            sum = (int)(num1[len1] - '0') + forward;
            if(sum >= 10)
            {
                sum -= 10;
                forward = 1;
            }
            else forward = 0;
            result.insert(0, to_string(sum));
            len1--;
        }
        while(len2 >= 0)
        {
            sum = (int)(num2[len2] - '0') + forward;
            if(sum >= 10)
            {
                sum -= 10;
                forward = 1;
            }
            else forward = 0;
            result.insert(0, to_string(sum));
            len2--;
        }

        if(forward == 1) result.insert(0, "1");

        return result;
    }
};


