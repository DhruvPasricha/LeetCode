class Solution {
    
public:
    bool isSymmetric(TreeNode* root) {   
        
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root->left, root->right});
        
        
        while(!q.empty()) {
            
            auto [root1, root2] = q.front();
            
            q.pop();
            
            if(root1 == NULL and root2 == NULL)
                continue;
        
            if(root1 == NULL or root2 == NULL)
                return false;
            
            if(root1 -> val != root2 -> val)
                return false;
            
            q.push({root1->right, root2->left});
            q.push({root1->left, root2->right});
            
        }
        
        return true;
    }
};