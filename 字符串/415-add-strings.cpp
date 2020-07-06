/*

415. �ַ������
���������ַ�����ʽ�ķǸ����� num1 ��num2 ���������ǵĺ͡�

ע�⣺

num1 ��num2 �ĳ��ȶ�С�� 5100.
num1 ��num2 ��ֻ�������� 0-9.
num1 ��num2 ���������κ�ǰ���㡣
�㲻��ʹ���κ΃Ƚ� BigInteger �⣬ Ҳ����ֱ�ӽ�������ַ���ת��Ϊ������ʽ��




˼·1��
������ӣ����������ַ�������ĩλ��ӣ�ʹ��һ��������¼��λ��
��������ʱ�ڽ���Ŀ�ͷ���롣

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


