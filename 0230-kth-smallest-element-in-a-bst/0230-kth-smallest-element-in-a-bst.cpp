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

class Compare{
    public:
    bool operator()(int a , int b ){
        return a < b;
    }
};


class Solution {

private:
    void traverseBST(TreeNode* root , int k , priority_queue<int , vector<int> , Compare>& pq){
        if (!root) return;
        pq.push(root -> val);
        if (pq.size() >k) pq.pop();
        traverseBST(root-> left , k , pq);
        traverseBST(root->right , k ,pq);
    }


public:
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int , vector<int> , Compare> pq;
        traverseBST(root , k , pq);

        cout<<pq.size();
        return pq.top();



    }
};
