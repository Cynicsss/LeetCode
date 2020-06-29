/*
7. 整数反转  难度：简单
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21


思路：
神奇的一道题，debug n次

ps： if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7))
官方的第二个判断条件中判断了pop的值，来判断是否越界，但是由于题目给定的是int型的数据，范围为-2147483648到2147483647，所以逆序输出的时候，当rev == INT_MAX，rev== INT_MIN，第十位的数字加入的即是原来的首位，pop只能在-2到2之间，就不会大于7或者小于-8，造成越界了。

所以在本题中省略了第二个判断条件，情况较为特殊，一般情况下还是要考虑第二个条件。
*/


class Solution {
public:
    int reverse(int x)
    {
        if(x == 0) return 0;
        int result = 0;
        while(x != 0)
        {
            int pop = x % 10;
            if(result > (INT_MAX / 10) || (result == (INT_MAX / 10) && pop > 7)) return 0;
            if(result < (INT_MIN / 10) || (result == (INT_MIN / 10) && pop < -8)) return 0;
            result = result * 10 + pop;
            x = x / 10;
        }
        return result;
    }
};
