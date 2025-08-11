/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {

private:
    //int maxLeftDepth;
    //int maxRightDepth;
    int diameter ;

    int findMaxDepth(TreeNode* root){
        if (!root) return 0;
        return 1 + max(findMaxDepth(root->left) , findMaxDepth(root->right));

    }

    void preOrderTraverse(TreeNode* root){
        if (!root) return ;
        helper(root->left , root->right);
        preOrderTraverse(root->left);
        preOrderTraverse(root->right);
    }

    void helper(TreeNode* left , TreeNode* right){
        diameter = max(findMaxDepth(left) + findMaxDepth(right) , diameter);
    }

public:
    Solution(): diameter (0)
        {

        }

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        preOrderTraverse(root);
        return diameter;
    }
};
