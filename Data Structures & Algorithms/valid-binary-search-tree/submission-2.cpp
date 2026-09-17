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
    bool isValidBST(TreeNode* root) {
        vector<int> traversal;
        return inOrder(root,traversal);
    }

    bool inOrder(TreeNode* root,vector<int> &traversal){
        
        if(root == nullptr) return true;
        bool left = inOrder(root->left,traversal);
        
        if(traversal.size()!=0){
            if(traversal[traversal.size()-1]>=root->val) return false;
        }
        
        traversal.push_back(root->val);
       
        bool right = inOrder(root->right, traversal);
        return left && right;
    }
   
};
