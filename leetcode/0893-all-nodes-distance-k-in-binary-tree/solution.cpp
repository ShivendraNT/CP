/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markparents(TreeNode*root,unordered_map<TreeNode*,TreeNode*> & parent_track){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left){
                parent_track[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent_track[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent_track;
        markparents(root,parent_track);
        
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        visited[target]=1;
        q.push(target);
        int curr_level=0;
        while(!q.empty()){
            int size=q.size();
            if(curr_level++ ==k) break;
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left]=1;
                }
                if(curr->right&&!visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right]=1;
                }
                if(parent_track[curr] && !visited[parent_track[curr]]){
                    q.push(parent_track[curr]);
                    visited[parent_track[curr]]=1;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
