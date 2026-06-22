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
    void preorder(TreeNode*root,vector<TreeNode*>& pre){
        if(!root) return;
        pre.push_back(root);
        preorder(root->left,pre);
        preorder(root->right,pre);
    }
    void flatten(TreeNode* root) {
        if(!root) return;
        vector<TreeNode*> pre;
        preorder(root,pre);
        TreeNode* prev=root;
        for(int i=1;i<pre.size();i++){
            TreeNode*curr=pre[i];
            prev->left=NULL;
            prev->right=curr;
            prev=curr;
        }
        return;
    }
};
