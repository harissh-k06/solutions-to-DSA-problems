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



public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return root;

        int maxVal = max(p->val , q->val);
        int minVal = min(p->val , q->val);

        if (maxVal < root->val){
            return lowestCommonAncestor(root -> left , p , q);
        }

        else if (minVal > root->val){
            return lowestCommonAncestor(root -> right , p , q);
        }

        else return root;

    }
};
