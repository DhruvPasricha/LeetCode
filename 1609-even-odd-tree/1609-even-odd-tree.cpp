class Solution {
    
    
    void dfs(TreeNode* root, vector<vector<int>> &Tree, int lvl) {
        
        if(root == NULL) return;
        
        if(lvl >= Tree.size()) Tree.push_back({});
        
        
        Tree[lvl].push_back(root->val);
        
        dfs(root->left,Tree, lvl + 1);
        dfs(root->right,Tree, lvl + 1);
        
    }
    
    bool check(vector<int> &arr, int prev, bool (*f)(int, int), int lvl) {
        
        for(int &x : arr) {
            bool ok = ((lvl & 1) ^ (x & 1));
            ok &= f(prev, x);
            if(not ok) return false;
            prev = x; 
        }
        return true;
    }
public:
    bool isEvenOddTree(TreeNode* root) {
        
        if(root == NULL) return true;
        
        vector<vector<int>> Tree;
        
        dfs(root, Tree, 0);
        
        int n = Tree.size();
        
        bool ans = true;
        for(int i = 0;i < n;i++) {
            
            if(i & 1) 
                ans = check(Tree[i], INT_MAX, [](int x, int y) -> bool {return x > y;},i);
            else 
                ans = check(Tree[i], INT_MIN, [](int x, int y) -> bool {return x < y;},i);
            
            if(ans == false) break;
        }
        
        return ans;
    }
};