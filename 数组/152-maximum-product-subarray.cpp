/*

152. �˻����������  �Ѷȣ��е�
����һ���������� nums �������ҳ������г˻��������������飨�������������ٰ���һ�����֣��������ظ�����������Ӧ�ĳ˻���



ʾ�� 1:

����: [2,3,-2,4]
���: 6
����: ������ [2,3] �����˻� 6��
ʾ�� 2:

����: [-2,0,-1]
���: 0
����: �������Ϊ 2, ��Ϊ [-2,-1] ���������顣


˼·��

��Ϊ���ڸ������������ֻά��һ��״̬ת�Ʒ����ǲ����ģ����Դ�����Ҫά������״̬ת�Ʒ��̣�һ����¼�˻���Сֵ��һ����¼�˻����ֵ��ÿ���ж���Ҫ�ж�max��min�뵱ǰԪ�صĴ�С��
ʱ�临�ӶȺͿռ临�Ӷȶ�ΪO(n)

*/

class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int len = nums.size();
        if(len == 0) return 0;
        vector<int> dp_max(len), dp_min(len);
        dp_max[0] = nums[0];
        dp_min[0] = nums[0];
        for(int i = 1; i < len; i++)
        {
            dp_max[i] = max(nums[i], max(dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]));
            dp_min[i] = min(nums[i], min(dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]));
        }
        int Max = dp_max[0];
        for(int i = 0; i < len; i++)
            Max = max(Max, dp_max[i]);
        return Max;
    }
};

/*

�Ż��ռ临�Ӷȣ�

ֻ������������ά��״̬��ͬʱ��¼��ǰ���ֵ ��󷵻����ֵ����

*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxF = nums[0], minF = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int mx = maxF, mn = minF;
            maxF = max(mx * nums[i], max(nums[i], mn * nums[i]));
            minF = min(mn * nums[i], min(nums[i], mx * nums[i]));
            ans = max(maxF, ans);
        }
        return ans;
    }
};
