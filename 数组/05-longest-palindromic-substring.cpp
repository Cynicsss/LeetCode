/*
�������������� ��̬�滮

����һ����ά����dp���к��зֱ�����ַ���sÿ���ַ����±꣬��dp[i][j]�����±�Ϊi-j֮����Ӵ����Ƿ�Ϊ�����Ӵ���1��0��¼��
���ж�dp[i-1][j+1]��ʱ��ֻҪ����s[i-1]==s[j+1]��dp[i][j]==1���Ϊ�����Ӵ���


*/
class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.size();
        if(len==0||len==1)
            return s;
        int start=0;//���Ĵ���ʼλ��
        int max=1;//���Ĵ���󳤶�
        vector<vector<int>>  dp(len,vector<int>(len));//�����ά��̬����
        for(int i=0;i<len;i++)//��ʼ��״̬
        {
            dp[i][i]=1;
            if(i<len-1&&s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                max=2;
                start=i;
            }
        }
        for(int l=3;l<=len;l++)//l��ʾ�������Ӵ����ȣ�����3��ʾ�ȼ�������Ϊ3���Ӵ�
        {
            for(int i=0;i+l-1<len;i++)
            {
                int j=l+i-1;//��ֹ�ַ�λ��
                if(s[i]==s[j]&&dp[i+1][j-1]==1)//״̬ת��
                {
                    dp[i][j]=1;
                    start=i;
                    max=l;
                }
            }
        }
        return s.substr(start,max);//��ȡ������Ӵ�
    }
};
