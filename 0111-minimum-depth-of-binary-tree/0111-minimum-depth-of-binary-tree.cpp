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




int helper(TreeNode* node){
    if (!node) return 0;
    if (!node->left) return 1 + helper(node->right);
    else if (!node->right) return 1 + helper(node->left);
    else return 1 + min(helper(node->left) , helper(node->right));
}


public:
    int minDepth(TreeNode* root) {
        return helper(root);
    }
};