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
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*, unsigned long long int>> q;
        
        q.push({root, 0});
        q.push({NULL, 0});
        
        unsigned long long int low = 0;
        unsigned long long int high = 0;
        unsigned long long int ans = 0;
        
        while(q.size() > 0) {
            
            auto [current, index] = q.front();
            q.pop();
            
            
            if(current == NULL) {
                // previous level is completed
                ans = max(high - low + 1, ans);
                
                if(q.size() > 0) {
                    
                    q.push({NULL, 0});
                    low = q.front().second;
                    
                }
            } else {
                
                high = index;
                
                if(current->left)
                    q.push({current->left, 2ll * index});


                if(current->right)
                    q.push({current->right, 2ll * index + 1});
            }
        }
        
        
        return ans;
    }
};