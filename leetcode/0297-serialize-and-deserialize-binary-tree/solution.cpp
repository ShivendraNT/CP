/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr==NULL){
                s.append("#,");
                continue;
            }
            s.append(to_string(curr->val)+',');
            q.push(curr->left);
            q.push(curr->right);
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream ss(data);
        string str;
        queue<TreeNode*> q;
        getline(ss, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if (!getline(ss, str, ',')) break; 
            TreeNode* left;
            if(str != "#"){
                left=new TreeNode(stoi(str));
                q.push(left);
            }
            else{
                left=NULL;
            }
            if (!getline(ss, str, ',')) break;
            TreeNode* right;
            if(str != "#"){
                right=new TreeNode(stoi(str));
                q.push(right);
            }
            else{
                right=NULL;
            }
            curr->left=left;
            curr->right=right;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
