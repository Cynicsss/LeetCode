/* 56.�ϲ�����
��Ŀ������
����һ�����伯�ϣ���ϲ������ص������䡣
ʾ��1:
```
����: [[1,3],[2,6],[8,10],[15,18]]
���: [[1,6],[8,10],[15,18]]
����: ���� [1,3] �� [2,6] �ص�, �����Ǻϲ�Ϊ [1,6].
```

ʾ��2:
```
����: [[1,4],[4,5]]
���: [[1,5]]
����: ���� [1,4] �� [4,5] �ɱ���Ϊ�ص����䡣
```

## ˼·
���ȶ���������Ԫ�ؽ��������ź��������֮����������ľͺ��ж��ˣ�

�ж����������Ԫ���Ƿ���ھ�������Ҽ��ޣ�������ڣ���ֱ�ӽ���������뵽���vector�У����С�ڣ��ж���������ֵ���������ֵ��С����Ļ����¾�������ֵΪ��������ֵ��С�Ļ�ֱ��������

## ����
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>> result;
        if(intervals.size() == 0) return result;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){return a[0] < b[0];});
        for(int i = 0; i < intervals.size(); i++)
        {
            if(result.size() == 0)
                result.push_back(intervals[i]);
            else
            {
                if(intervals[i][0] > result[result.size() - 1][1]) result.push_back(intervals[i]);
                else
                {
                    if(intervals[i][1] <= result[result.size() - 1][1]) continue;
                    else
                        result[result.size() - 1][1] = intervals[i][1];
                }
            }
        }
        return result;
    }
};
