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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        helper(root,maxDiameter);
        return maxDiameter;
    }

    int helper(TreeNode* root, int &maxDiameter){
        if(root==nullptr) return 0;
        if(root->left == nullptr &&  root->right == nullptr) return 1;

        int left = helper(root->left,maxDiameter);
        int right = helper(root->right, maxDiameter);
        
        maxDiameter = max(maxDiameter,left + right);
        
        return 1 + max(left,right);
    }
};
