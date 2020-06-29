/*

102. �������Ĳ������ �Ѷȣ��е�
����һ�������������㷵���䰴 ������� �õ��Ľڵ�ֵ�� �������أ������ҷ������нڵ㣩��



ʾ����
��������[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
�������α��������

[
  [3],
  [9,20],
  [15,7]
]


˼·��
���ö��б���ͬһ����
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> result;
        if(root == NULL) return result;
        queue<TreeNode*> TreeQue;
        TreeQue.push(root);
        while(!TreeQue.empty())
        {
            int len = TreeQue.size();
            vector<int> temp_val;
            for(int i = 0; i < len; i++)
            {
                TreeNode *temp = TreeQue.front();
                TreeQue.pop();
                temp_val.push_back(temp -> val);
                if(temp -> left != NULL) TreeQue.push(temp -> left);
                if(temp -> right != NULL) TreeQue.push(temp -> right);
            }
            result.push_back(temp_val);
        }
        return result;
    }
};
