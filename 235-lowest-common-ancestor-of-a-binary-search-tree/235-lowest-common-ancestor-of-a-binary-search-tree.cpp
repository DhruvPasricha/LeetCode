class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL)
            return NULL;
        
        if(root == p or root == q)
            return root;
        
        auto leftAns = lowestCommonAncestor(root->left, p, q);
        auto rightAns = lowestCommonAncestor(root->right, p, q);
        
        if(leftAns != NULL and rightAns != NULL) 
            return root;
        
        if(leftAns)
            return leftAns;
        
        return rightAns;
    
    }
};