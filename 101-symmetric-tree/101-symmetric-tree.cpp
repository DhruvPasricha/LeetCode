class Solution {
    
public:
    bool isSymmetric(TreeNode* root) {   
        
        stack<pair<TreeNode*, TreeNode*>> st;
        st.push({root->left, root->right});
        
        
        while(!st.empty()) {
            
            auto [root1, root2] = st.top();
            
            st.pop();
            
            if(root1 == NULL and root2 == NULL)
                continue;
        
            if(root1 == NULL or root2 == NULL)
                return false;
            
            if(root1 -> val != root2 -> val)
                return false;
            
            st.push({root1->right, root2->left});
            st.push({root1->left, root2->right});
            
        }
        
        return true;
    }
};