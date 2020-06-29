/*
14. �����ǰ׺  �Ѷȣ���
��дһ�������������ַ��������е������ǰ׺��

��������ڹ���ǰ׺�����ؿ��ַ��� ""��

ʾ�� 1:

����: ["flower","flow","flight"]
���: "fl"
ʾ�� 2:

����: ["dog","racecar","car"]
���: ""
����: ���벻���ڹ���ǰ׺��
˵��:

��������ֻ����Сд��ĸ a-z ��


˼·1��

��򵥵�˼·���Ǳ�����ٱ�����ʱ��Ҳͨ����   ʱ�临�Ӷ�ΪO(mn)
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
˼·2
����ɨ��

��һ�ַ���������ɨ�衣����ɨ��ʱ����ǰ������������ַ�����ÿһ�У��Ƚ���ͬ���ϵ��ַ��Ƿ���ͬ�������ͬ���������һ�н��бȽϣ��������ͬ��ǰ�в������ڹ���ǰ׺����ǰ��֮ǰ�Ĳ���Ϊ�����ǰ׺��

ʱ�临�Ӷ�ͬ��ΪO(mn)

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
˼·3
������������
https://leetcode-cn.com/problems/longest-common-prefix/solution/zui-chang-gong-gong-qian-zhui-by-leetcode-solution/
ʱ�临�Ӷ�:O(mn)
�ռ临�Ӷ�:O(mlogn)

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



