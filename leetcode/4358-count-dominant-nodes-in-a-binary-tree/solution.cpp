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
    int dominant(TreeNode* root,int & cnt){
        if(root==NULL){
            return -1;
        }
        int val=root->val;
        int maxchildren=-1;
        maxchildren=max(dominant(root->left,cnt),dominant(root->right,cnt));
        if(val>=maxchildren){
            cnt++;
            return val;
        }
        return maxchildren;
    }
    int countDominantNodes(TreeNode* root) {
        int cnt=0;
        int val=dominant(root,cnt);
        return cnt;
    }
};
