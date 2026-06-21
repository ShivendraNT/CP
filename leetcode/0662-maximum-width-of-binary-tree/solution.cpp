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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*,long long>>q;
        unsigned long long ans=1;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            unsigned long long start_idx = q.front().second;
            unsigned long long maxleft = ULLONG_MAX;
            unsigned long long maxright = 0;
            for(int i=0;i<n;i++){
                auto p=q.front();
                q.pop();
                TreeNode* node=p.first;
                unsigned long long pos = p.second - start_idx;
                maxleft=min(pos,maxleft);
                maxright=max(maxright,pos);
                if(node->left) q.push({node->left,2*pos+1});
                if(node->right) q.push({node->right,2*pos+2});
            }
            ans=max(ans,maxright-maxleft+1);
        }
        return ans;
    }
};
