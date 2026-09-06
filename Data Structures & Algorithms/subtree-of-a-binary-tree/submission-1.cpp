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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr || subRoot == nullptr) return false;

        bool curr = helper(root,subRoot);
        
        bool left =  isSubtree(root->left,subRoot);
        bool right = isSubtree(root->right,subRoot);

        return curr || left || right;
    }

    bool helper(TreeNode* p, TreeNode* q){
        if(p==nullptr && q == nullptr) return true;
        else if(p == nullptr || q == nullptr) return false;

        if(p->val == q->val){
            bool left = helper(p->left, q->left);
            bool right = helper(p->right, q->right);
            return left && right;
        }
        return false;

    }
};
