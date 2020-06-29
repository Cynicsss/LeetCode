/*

102. 二叉树的层序遍历 难度：中等
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。



示例：
二叉树：[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]


思路：
采用队列保存同一层结点
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
