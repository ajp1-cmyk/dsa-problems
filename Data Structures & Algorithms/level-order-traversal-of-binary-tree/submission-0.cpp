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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
       if(root == nullptr) return ans;
         vector<int> list;
        queue<TreeNode*> tree;
        tree.push(root);
        tree.push(nullptr);

        while(!tree.empty()){
                TreeNode* curr;
                curr = tree.front();
                tree.pop();

                if(curr == nullptr){
                      ans.push_back(list);
                    if(!tree.empty()){
                        tree.push(nullptr); 
                        list.resize(0);
                    }
                }else{

                    list.push_back(curr->val);
                    if(curr->left) tree.push(curr->left);
                    if(curr->right) tree.push(curr->right);
                }

        }
        
        return ans;
    }
};
