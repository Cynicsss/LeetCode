/*
46. ȫ���� �Ѷȣ��е�
����һ�� û���ظ� ���ֵ����У����������п��ܵ�ȫ���С�

ʾ��:

����: [1,2,3]
���:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]


˼·��
���ݷ���Ҫ���ջ��ݷ�ģ�壬�ҵ�����������Ƶݹ�
����Ҫ��ȷ����Ϊ�����ظ����飬����ֻҪ����Ԫ��λ�������仯���Ǳ��ǲ�ͬ�����У����Բ��õ����ظ����⡣

*/

class Solution {
public:

    void perm_tool(vector<vector<int>> &result, vector<int> &out, int cur, int length)
    {
        if(cur == length)
        {
            result.push_back(out);
            return;
        }
        for(int i = cur; i < length; i++)
        {
            swap(out[i], out[cur]);
            perm_tool(result, out, cur+1, length);
            swap(out[i], out[cur]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> result;
        perm_tool(result, nums, 0, nums.size());
        return result;
    }
};
