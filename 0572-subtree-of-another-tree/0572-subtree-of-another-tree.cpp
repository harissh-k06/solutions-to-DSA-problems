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

    vector<TreeNode*> allCandidates;

    bool isSameTree(TreeNode* p , TreeNode* q){
        if (!p && !q) return true;
        else if (!p || !q) return false;
        else if (p->val != q->val) return false;
        else return isSameTree(p->left , q->left) && isSameTree(p->right , q->right);
    }

    void findSubRoot(TreeNode* root, int subRootVal){
        if (!root) return;
        if (root->val == subRootVal) allCandidates.emplace_back(root);
        findSubRoot(root->left , subRootVal);
        findSubRoot(root->right , subRootVal);  

        //O(n)
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        findSubRoot(root , subRoot->val);
        for (auto& candidate : allCandidates){
            if (isSameTree(candidate , subRoot)) return true;
        }
        return false;
    }
};
