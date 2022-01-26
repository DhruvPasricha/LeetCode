class Solution {
    
    void merge(vector<int> &A, vector<int> &B, vector<int> &Ans) {
        
        int i = 0;
        int n = A.size();
        int j = 0;
        int m = B.size();
        
        Ans.resize(m + n);
        
        while(i < n or j < m) {
            int option1 = (i < n) ? A[i] : INT_MAX;
            int option2 = (j < m) ? B[j] : INT_MAX;
            
            if(option1 <= option2)
                Ans[i + j] = option1, i++;
            else
                Ans[i + j] = option2, j++;
        } 
    }
    
    void getInorder(TreeNode* root, vector<int> &Ans) {
        
        if(root == NULL)
            return;
        
        getInorder(root->left, Ans);
        Ans.push_back(root->val);
        getInorder(root->right, Ans);
    }
    
    
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        vector<int> tree1;
        getInorder(root1, tree1);
        
        vector<int> tree2;
        getInorder(root2, tree2);
        
        vector<int> Ans;
        merge(tree1, tree2, Ans);
        
        return Ans;
    }
};
