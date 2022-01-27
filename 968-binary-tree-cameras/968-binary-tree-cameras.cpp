class Solution {
    unordered_map<TreeNode*, int64_t> dp[2][2];
    
    int64_t solve(TreeNode* root, bool mandatory, bool covered) {
        
        if(root == NULL) {
            if(mandatory) return INT_MAX;
            return 0;
        }
        
        if(dp[mandatory][covered].count(root)) 
            return dp[mandatory][covered][root];
        
        // kept here
        int64_t ans = 1 + solve(root->left, false, true) + solve(root->right, false, true);
        
        
        // skipped
        if(not mandatory) {
            
            int64_t ans1 = solve(root->left, not covered, false) + solve(root->right, false, false);
            int64_t ans2 = solve(root->left, false, false) + solve(root->right, not covered, false);
            
            ans = min({ans, ans1, ans2});
        }
        
        return dp[mandatory][covered][root] = ans;   
    }
    
public:
    int minCameraCover(TreeNode* root) {
         
        return solve(root, false, false);
    }
};