/*
94. ���������������   �Ѷȣ��е�
����һ���������������������� ������

ʾ��:

����: [1,null,2,3]
   1
    \
     2
    /
   3

���: [1,3,2]
����: �ݹ��㷨�ܼ򵥣������ͨ�������㷨�����


˼·1��
�ݹ�
ʱ�临�Ӷȣ�O(n) �ռ临�Ӷȣ�O(n)
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

    void BL(vector<int> &result, TreeNode *root)
    {
        if(root == NULL) return;
        BL(result, root -> left);
        result.push_back(root -> val);
        BL(result, root -> right);
    }

    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> result;
        if(root == NULL) return result;
        BL(result, root);
        return result;
    }
};

/*
������
ʹ��ջ  ʱ�临�Ӷ�O(n) �ռ�O(n)
*/

public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> result;
        if(root == NULL) return result;
        stack<TreeNode*> stk;
        TreeNode *temp = root;
        while(temp != NULL || !stk.empty())
        {
            while(temp != NULL)
            {
                stk.push(temp);
                temp = temp -> left;
            }
            temp = stk.top();
            stk.pop();
            result.push_back(temp -> val);
            temp = temp -> right;
        }
        return result;
    }
};
