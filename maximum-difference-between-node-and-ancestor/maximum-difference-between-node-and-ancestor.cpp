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
    int maxAncestorDiff(TreeNode* root, int mx = INT_MIN, int mn = INT_MAX) {
        
        if(root == NULL) {
            return INT_MIN;
        }
        
        int nextMax = max(root->val, mx);
        int nextMin =  min(root->val, mn);
        
        int ans1 = maxAncestorDiff(root->left, nextMax, nextMin);
        int ans2 = maxAncestorDiff(root->right, nextMax, nextMin);
        
        int ans = max(ans1, ans2);
        
        if(mx != INT_MIN) ans = max({ans, abs(root->val - mn), abs(root->val - mx)});
        
        return ans;
    }
};