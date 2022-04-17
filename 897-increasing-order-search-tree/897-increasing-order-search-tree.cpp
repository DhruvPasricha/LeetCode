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
    
    TreeNode *head;
    TreeNode *tail;
    
    void solve(TreeNode* root) {
        
        if(root == NULL) return;
        
        solve(root->left);
        tail -> right = new TreeNode(root->val);
        tail = tail -> right;
        solve(root->right);
    }
    
public:
    TreeNode* increasingBST(TreeNode* root) {
        
        head = tail = new TreeNode(INT_MIN);
        solve(root);
        return head -> right;
    }
};