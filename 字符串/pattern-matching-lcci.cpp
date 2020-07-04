/*

������ 16.18. ģʽƥ��  �Ѷ�:�е� ���˸о�����
���������ַ�������pattern��value�� pattern�ַ�������ĸ"a"��"b"��ɣ����������ַ����е�ģʽ�����磬�ַ���"catcatgocatgo"ƥ��ģʽ"aabab"������"cat"��"a"��"go"��"b"�������ַ���Ҳƥ����"a"��"ab"��"b"������ģʽ������ע��"a"��"b"����ͬʱ��ʾ��ͬ���ַ�������дһ�������ж�value�ַ����Ƿ�ƥ��pattern�ַ�����

ʾ�� 1��

���룺 pattern = "abba", value = "dogcatcatdog"
����� true
ʾ�� 2��

���룺 pattern = "abba", value = "dogcatcatfish"
����� false
ʾ�� 3��

���룺 pattern = "aaaa", value = "dogcatcatdog"
����� false
ʾ�� 4��

���룺 pattern = "abba", value = "dogdogdogdog"
����� true
���ͣ� "a"="dogdog",b=""����֮Ҳ���Ϲ���
��ʾ��

1 <= len(pattern) <= 1000
0 <= len(value) <= 1000
����Լ���patternֻ������ĸ"a"��"b"��value������Сд��ĸ��



˼·1��
ö��
�ٷ���˼·��������������

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
˼·2��
�ο�һ��ͬѧ����⣬�����׶� �ǳ�ţ��

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







