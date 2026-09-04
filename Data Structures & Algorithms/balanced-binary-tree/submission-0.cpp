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
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        if(root->left==nullptr && root->right == nullptr) return true;

        bool flag=true;
        helper(root,flag);
        return flag;
    }

    int helper(TreeNode* root, bool &flag){
        if(root == nullptr) return 0;
        
        int left = helper(root->left,flag);
        int right = helper(root->right,flag);
        int diff = abs(left-right);
        if(diff > 1) {
            flag = false;
        }
        return 1 + max(left,right);
    }
};
