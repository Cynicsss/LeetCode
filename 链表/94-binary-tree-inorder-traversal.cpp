/*
94. 二叉树的中序遍历   难度：中等
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？


思路1：
递归
时间复杂度：O(n) 空间复杂度：O(n)
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
迭代：
使用栈  时间复杂度O(n) 空间O(n)
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
