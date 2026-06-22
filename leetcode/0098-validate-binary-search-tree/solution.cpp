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
    bool validate(TreeNode* root,long long max_val,long long min_val){
        if(!root) return true;
        if(root->val<=min_val || root->val>=max_val) return false;
        return validate(root->left,root->val,min_val) && validate(root->right,max_val,root->val);
    }
    bool isValidBST(TreeNode* root) {
        return validate(root,LONG_MAX,LONG_MIN);
    }
};
