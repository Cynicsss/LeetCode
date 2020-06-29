/*
20. ��Ч������  �Ѷȣ���
����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ������ж��ַ����Ƿ���Ч��

��Ч�ַ��������㣺

�����ű�������ͬ���͵������űպϡ�
�����ű�������ȷ��˳��պϡ�
ע����ַ����ɱ���Ϊ����Ч�ַ�����

ʾ�� 1:

����: "()"
���: true
ʾ�� 2:

����: "()[]{}"
���: true
ʾ�� 3:

����: "(]"
���: false
ʾ�� 4:

����: "([)]"
���: false
ʾ�� 5:

����: "{[]}"
���: true


˼·��
���������жϼ���

*/
class Solution {
public:
    bool isValid(string s)
    {
        stack<char> brackets;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                brackets.push(s[i]);
            else if(s[i] == ')')
            {
                if(brackets.size() == 0) return false;
                if(brackets.top() == '(')
                {
                    brackets.pop();
                    continue;
                }
                else
                    return false;
            }
            else if(s[i] == ']')
            {
                if(brackets.size() == 0) return false;
                if(brackets.top() == '[')
                {
                    brackets.pop();
                    continue;
                }
                else
                    return false;
            }
            else if(s[i] == '}')
            {
                if(brackets.size() == 0) return false;
                if(brackets.top() == '{')
                {
                    brackets.pop();
                    continue;
                }
                else
                    return false;
            }
            else
                return false;
        }
        if(brackets.size() == 0) return true;
        else return false;
    }
};
