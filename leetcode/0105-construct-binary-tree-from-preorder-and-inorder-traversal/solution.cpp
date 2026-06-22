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
    TreeNode* build(vector<int> & preorder,int prestart,int preend,vector<int>& inorder,int instart,int inend,unordered_map<int,int>& mpp){
        if(prestart>preend || instart>inend) return NULL;
        TreeNode* root=new TreeNode(preorder[prestart]);
        int inroot=mpp[root->val];
        int numsleft=inroot-instart;

        root->left=build(preorder,prestart+1,prestart+numsleft,inorder,instart,inroot-1,mpp);
        root->right=build(preorder,prestart+numsleft+1,preend,inorder,inroot+1,inend,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mpp;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mpp[inorder[i]]=i;
        }
        TreeNode* root=build(preorder,0,n-1,inorder,0,n-1,mpp);
        return root;
    }
};
