/*
70. ��¥�� �Ѷȣ���
������������¥�ݡ���Ҫ n ������ܵ���¥����

ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�

ע�⣺���� n ��һ����������

ʾ�� 1��

���룺 2
����� 2
���ͣ� �����ַ�����������¥����
1.  1 �� + 1 ��
2.  2 ��
ʾ�� 2��

���룺 3
����� 3
���ͣ� �����ַ�����������¥����
1.  1 �� + 1 �� + 1 ��
2.  1 �� + 2 ��
3.  2 �� + 1 ��


˼·1��
��̬�滮
O(n) O(n)
*/

class Solution {
public:
    int climbStairs(int n)
    {
        vector<int> dp(n);
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2; i < n; i++)
            dp[i] = dp[i - 2] + dp[i - 1];
        return dp[n - 1];
    }
};


/*
˼·2��

�ռ临�Ӷ��Ż�ΪO(1):


*/
class Solution {
public:
    int climbStairs(int n) {
        int p = 0, q = 0, r = 1;
        for (int i = 1; i <= n; ++i) {
            p = q;
            q = r;
            r = p + q;
        }
        return r;
    }
};

