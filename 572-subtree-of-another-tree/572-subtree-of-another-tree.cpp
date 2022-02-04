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
    
    bool isSame(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL) return root2 == NULL;
        if(root2 == NULL) return false;
        return root1 -> val == root2 -> val and isSame(root1 -> left, root2 -> left) and isSame(root1 -> right, root2 -> right);
    }
    
    
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL) return subRoot == NULL;
        if(subRoot == NULL) return false;
        return isSame(root, subRoot) or isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }
};