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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root)
            q.push(root);
        while (!q.empty()){
            int levelSize = q.size();
            vector<int> level;
            for (int i = 1 ; i <= levelSize ; i++){
                TreeNode* frontNode = q.front();
                level.emplace_back(frontNode->val);
                q.pop();
                if (frontNode->left){
                    q.push(frontNode->left);
                }
                if (frontNode->right){
                    q.push(frontNode->right);
                }
            }
            res.emplace_back(level);
        }
        return res;
    }
};
