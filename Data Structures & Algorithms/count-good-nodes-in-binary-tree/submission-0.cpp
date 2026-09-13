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
    int goodNodes(TreeNode* root) {
        int biggest = root->val;
        int count = 0;
        helper(root, biggest, count);
        return count;
    }

    void helper(TreeNode* root, int biggest, int &count){
        
        if(root == nullptr) return;
        
        if(root->val>=biggest){
            count++;
            biggest = root->val;
        }

        helper(root->left, biggest, count);
        helper(root->right, biggest, count);

    }
};
