class BSTIterator {
    
    vector<int> arr;
    
    void insert(TreeNode* root) {
        
        if(root == NULL)
            return;
        
        insert(root->left);
        arr.push_back(root->val);
        insert(root->right);
        
    }
    
public:
    BSTIterator(TreeNode* root) {
        insert(root);
        reverse(arr.begin(), arr.end());
    }
    
    int next() {
        
        int ans = arr.back();
        arr.pop_back();
        
        return ans;
    }
    
    bool hasNext() {
        
        return arr.size() > 0;
    }
};
