class Solution {
public:
    class Node {
    public:
        int maxnode;
        int minnode;
        int sum;
        Node(int maxnode, int minnode, int sum) {
            this->maxnode = maxnode;
            this->minnode = minnode;
            this->sum = sum;
        }
    };

    int ans = 0; 

    Node largestBST(TreeNode* root) {
        if (!root) return Node(INT_MIN, INT_MAX, 0);

        auto left = largestBST(root->left);
        auto right = largestBST(root->right);

        if (left.maxnode < root->val && right.minnode > root->val) {
            int currentSum = left.sum + right.sum + root->val;
            ans = max(ans, currentSum); 
            
            return Node(max(root->val, right.maxnode), min(root->val, left.minnode), currentSum);
        }
        
        return Node(INT_MAX, INT_MIN, 0);
    }

    int maxSumBST(TreeNode* root) {
        ans = 0;
        largestBST(root);
        return ans;
    }
};
