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
    vector<int> inorderTraversal(TreeNode* root) {
            vector<int> answer;
            findInOrder(root , answer);
            return answer;
    }
    private:

    void findInOrder(TreeNode* root , vector<int>& answer){   
        if (root!=nullptr){
            findInOrder(root->left,answer);
            answer.push_back(root->val);
            findInOrder(root->right,answer);
        }
    }
};