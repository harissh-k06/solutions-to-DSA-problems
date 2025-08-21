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

vector<vector<int>> result;

private:

    void helper(TreeNode* node, vector<int>& subset){
        //leaf node
        if (!node ) return;
        if (!node->left && !node->right) {
            subset.emplace_back(node->val);
            result.emplace_back(subset);
            return;
        }
        subset.emplace_back(node->val);
        if (node ->left){
            helper(node->left , subset);
            subset.pop_back();
        }
        
        if (node->right){
            helper(node->right , subset);
            subset.pop_back();
        }
        //subset.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> subset;
        helper(root , subset);
        vector<string> ans;
        for (const auto & path : result){
            string p = "";
            for (int i = 0 ; i < path.size() -1; i++){
                p+= to_string(path[i]);
                p+="->";
            }
            p+=to_string(path[path.size() - 1]);
            ans.emplace_back(p);
        }
        return ans;
    }
};