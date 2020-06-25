/*
53. ��������  �Ѷȣ���
����һ���������� nums ���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�

ʾ��:

����: [-2,1,-3,4,-1,2,1,-5,4],
���: 6
����: ���������� [4,-1,2,1] �ĺ����Ϊ 6��
����:

������Ѿ�ʵ�ָ��Ӷ�Ϊ O(n) �Ľⷨ������ʹ�ø�Ϊ����ķ��η���⡣



˼·1��������
�����ˣ���ʱ


˼·2����̬�滮
dp[i]��ʾnums����nums[i]��β����������
dp[i] = max(dp[i - 1] + nums[i], nums[i]);
dp[i]ʱ��ǰ���֣�Ҫô����ǰ����������͵ĺͣ�Ҫô������

*/
class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int MAX = INT_MIN;
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int result = dp[0];
        for(int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            result = max(result, dp[i]);
        }
        return result;
    }
};

