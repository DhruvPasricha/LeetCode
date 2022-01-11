class Solution {
    int ans = 0;
    
    void solve(TreeNode* root, int parentSum = 0) {
        
        if(root -> left == NULL and root -> right == NULL) {
            ans += ((parentSum << 1) + root -> val);
            return;
        }
        if(root->left) solve(root->left, (parentSum << 1) + root->val);
        if(root->right) solve(root->right, (parentSum << 1) + root->val);
    }

public:
    int sumRootToLeaf(TreeNode* root) {
        solve(root);
        return ans;
    }
};