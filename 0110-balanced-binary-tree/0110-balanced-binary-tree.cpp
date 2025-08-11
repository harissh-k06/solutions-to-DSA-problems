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
    bool helper(TreeNode* root){
        if (!root) return true;
        else if (!root->left && !root->right) return true;
        else{
            int balanceFactor = abs(findDepth(root->left) - findDepth(root->right));
            if (balanceFactor > 1) return false;
            else return helper(root->left) && helper(root->right);
        }        
    }

    int findDepth(TreeNode* root){
        if (!root) return 0;
        return 1 + max(findDepth(root->left) , findDepth(root->right));
    }


public: 
    bool isBalanced(TreeNode *root) {
        return helper(root);
    }
};
