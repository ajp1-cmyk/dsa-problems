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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> list;
        queue<TreeNode*> tree;
        vector<int> ans;
        if(root==nullptr) return ans;
        tree.push(root);
        tree.push(nullptr);

        while(!tree.empty()){
           TreeNode* curr = tree.front();
            tree.pop();

            if(curr == nullptr && !tree.empty()){
                tree.push(nullptr);
            }

            if(curr != nullptr){
                if(curr->left) tree.push(curr->left);
                if(curr->right) tree.push(curr->right); 
                list.push_back(curr->val);   
            }else{
                ans.push_back(list[list.size()-1]);
                list.resize(0);
            }
        }

        return ans;
    }

};
