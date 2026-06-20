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
    int maxsum=INT_MIN;
    int maxpath(TreeNode* root){
        if(!root) return 0;

        int l=maxpath(root->left);
        int r=maxpath(root->right);
        maxsum=max(maxsum,max(0,l)+max(0,r)+root->val);
        int m=max(l,r);
        return root->val+max(m,0);
    }
    int maxPathSum(TreeNode* root) {
        int s=maxpath(root);
        return maxsum;
    }
};
