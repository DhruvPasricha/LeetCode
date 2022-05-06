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
    
    vector<double> ans;
    vector<int> count;
    
    void solve(TreeNode* root, int lvl) {
        
        if(root == NULL)
            return;
        
        if(lvl == ans.size()) {
            ans.push_back(0);
            count.push_back(0);
        }
        
        ans[lvl] += root->val;
        count[lvl]++;
        
        
        solve(root->left, lvl + 1);
        solve(root->right, lvl + 1);
    }
    
public:
    vector<double> averageOfLevels(TreeNode* root) {
        
        solve(root, 0);    
        
        int n = ans.size();
        
        for(int i = 0; i < n; i++)
            ans[i] /= count[i];
        
        return ans;
    }
};