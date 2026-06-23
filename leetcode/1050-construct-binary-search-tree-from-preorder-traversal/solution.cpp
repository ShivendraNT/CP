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
    TreeNode* construct(vector<int>& preorder,int prestart,int preend,vector<int> & inorder,int instart,int inend,unordered_map<int,int>&mpp){
        if(preend<prestart || inend<instart) return NULL;
        TreeNode* root=new TreeNode(preorder[prestart]);
        int loc=mpp[root->val]-instart;
        root->left=construct(preorder,prestart+1,prestart+loc,inorder,instart,instart+loc-1,mpp);
        root->right=construct(preorder,prestart+loc+1,preend,inorder,instart+loc+1,inend,mpp);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder=preorder;
        sort(inorder.begin(),inorder.end());
        unordered_map<int,int>mpp;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mpp[inorder[i]]=i;
        }
        return construct(preorder,0,n-1,inorder,0,n-1,mpp);
    }
};
