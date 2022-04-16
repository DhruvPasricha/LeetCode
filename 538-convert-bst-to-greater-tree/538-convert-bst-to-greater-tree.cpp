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
    
    int sumOfGreaterElements = 0;
    
public:
    TreeNode* convertBST(TreeNode* root) {
        
        if(root == NULL) 
            return root;
        
        root -> right = convertBST(root->right);
        
        root -> val += sumOfGreaterElements;
        sumOfGreaterElements = root->val;
        
        root -> left = convertBST(root->left);
        
        return root;
    }
};