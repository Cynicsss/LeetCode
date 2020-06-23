/*
3. ���ظ��ַ�����Ӵ�
����һ���ַ����������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�

ʾ�� 1:

����: "abcabcbb"
���: 3
����: ��Ϊ���ظ��ַ�����Ӵ��� "abc"�������䳤��Ϊ 3��
ʾ�� 2:

����: "bbbbb"
���: 1
����: ��Ϊ���ظ��ַ�����Ӵ��� "b"�������䳤��Ϊ 1��
ʾ�� 3:

����: "pwwkew"
���: 3
����: ��Ϊ���ظ��ַ�����Ӵ��� "wke"�������䳤��Ϊ 3��
     ��ע�⣬��Ĵ𰸱����� �Ӵ� �ĳ��ȣ�"pwke" ��һ�������У������Ӵ���



˼·1����������/˫ָ��

������ָ��a����ָ��b
bָ�����Ҳ�����{
    ��ÿ��A[b]�ж��Ƿ���֮ǰ��������ֹ���
        ������֣�ָ��aָ����ֹ���λ�õ���һ��λ�ã�
    ������ָ�����󳤶ȣ�
}

*/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        //s[start,end) ǰ����� ���治����
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
˼·2��
��hashmap�Ż�ʱ��
����hashmap����ֹ����ַ��������Ż�ʱ�䵽O(n)

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
