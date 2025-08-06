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

    bool isLeafNode(TreeNode* node){
        return (node->left == nullptr && node->right == nullptr); 
    }

    bool helper(TreeNode* node , long long lowerBound , long long upperBound){
        int nodeVal = node->val;
        if (!(nodeVal > lowerBound &&  nodeVal < upperBound )) return false;
        if (isLeafNode(node)) return true;
        bool flag = true;
        if (node->left){
            flag = helper(node->left , lowerBound , nodeVal);
        }
        if (node ->right ){
            flag = flag && helper(node->right , nodeVal, upperBound);
        }
        return flag;
    }

public:
    bool isValidBST(TreeNode* root) {
        //key idea -> for every node we set a local upper and lower bound within which the nodes value must be present
        return helper(root , LLONG_MIN , LLONG_MAX);
    }
};