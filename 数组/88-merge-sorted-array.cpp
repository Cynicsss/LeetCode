/*
88. �ϲ�������������  �Ѷȣ���
�������������������� nums1 �� nums2�����㽫 nums2 �ϲ��� nums1 �У�ʹ nums1 ��Ϊһ���������顣



˵��:

��ʼ�� nums1 �� nums2 ��Ԫ�������ֱ�Ϊ m �� n ��
����Լ��� nums1 ���㹻�Ŀռ䣨�ռ��С���ڻ���� m + n�������� nums2 �е�Ԫ�ء�


ʾ��:

����:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

���: [1,2,2,3,5,6]


˼·1��
�鲢����
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        vector<int> temp;
        for(int i = 0; i < m; i++)
            temp.push_back(nums1[i]);
        int l1 = 0, l2 = 0, k = 0;
        while(l1 < m && l2 < n)
        {
            if(temp[l1] <= nums2[l2])
                nums1[k++] = temp[l1++];
            else if(temp[l1] > nums2[l2])
                nums1[k++] = nums2[l2++];
        }
        while(l1 < m)
            nums1[k++] = temp[l1++];
        while(l2 < n)
            nums1[k++] = nums2[l2++];
    }
};


/*
˼·2��

�Ӻ���ǰ����Ƚ����������С��ѡȡ�����䵽nums1��β�����Ӻ���ǰ���Ա����ƶ�����Ԫ�ء�
���nums2�������ˣ�num1ʣ��Ԫ���ǲ���Ҫ����ģ����Ա�����ʱ��ֻ��Ҫ����nums2�����ǱȽϴ�С֮ǰҪ�ж�num1�Ƿ����꣬��������Խ�硣

*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = m + n - 1;
        while (n) {
            if (m == 0) {
                nums1[last--] = nums2[--n];
            } else if (nums2[n-1] > nums1[m-1]) {
                nums1[last--] = nums2[--n];
            } else {
                nums1[last--] = nums1[--m];
            }
        }
    }
};
