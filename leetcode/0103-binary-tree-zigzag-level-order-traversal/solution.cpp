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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        int i=0;
        stack<TreeNode*> st;
        st.push(root);
        vector<vector<int>> ans;
        while(!st.empty()){
            int n=st.size();
            vector<int> temp;
            stack<TreeNode*> st2;
            for(int j=0;j<n;j++){
                TreeNode* node=st.top();
                st.pop();
                temp.push_back(node->val);
                if(i%2==1){
                    if(node->right) st2.push(node->right);
                    if(node->left) st2.push(node->left);
                }
                else{
                    if(node->left) st2.push(node->left);
                    if(node->right) st2.push(node->right);
                }
            }
            ans.push_back(temp);
            st=st2;
            i++;
        } 
        return ans;
    }
};
