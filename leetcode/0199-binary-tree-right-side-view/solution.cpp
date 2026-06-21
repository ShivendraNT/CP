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
        if(!root) return {};
        queue<pair<TreeNode*,int>> nodes;
        map<int,int> mpp;
        nodes.push({root,0});
        while(!nodes.empty()){
            auto p=nodes.front();
            nodes.pop();
            TreeNode* node=p.first;
            int line=p.second;
            mpp[line]=node->val;
            if(node->left) nodes.push({node->left,line+1});
            if(node->right) nodes.push({node->right,line+1});
        } 
        vector<int> ans;
        for(auto p:mpp){
            ans.push_back(p.second);
        }
        return ans;
    }
};
