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
    TreeNode* findInOrderPre(TreeNode* root){
        TreeNode* temp = root;
        while (temp->right){
            temp = temp->right;
        }
        return temp;
    }

    void swapVal(TreeNode* root1 , TreeNode* root2){
        int temp = root1->val;
        root1->val = root2->val;
        root2->val = temp;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        else if (root-> val > key){
            root->left = deleteNode(root->left  , key);
        }
        else if (root->val < key){
            root->right = deleteNode(root->right , key);
        }
        else{
            
            if (!root->left){
                TreeNode* toDel = root;
                TreeNode* temp = root->right;
                delete toDel;
                return temp;
            }

            else if (!root->right){
                TreeNode* toDel = root;
                TreeNode* temp = root->left;
                delete toDel;
                return temp;
            }

            else{
                TreeNode* temp  = findInOrderPre(root->left);
                int toDelVal =root->val;
                swapVal(temp , root);            
                root->left  = deleteNode(root->left , toDelVal);
            }   
        }
        return root;
    }
};