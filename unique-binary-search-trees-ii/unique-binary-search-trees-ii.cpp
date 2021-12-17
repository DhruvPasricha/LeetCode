class Solution {
public:
    
    
    vector<TreeNode*> solve(int l, int r){
        
        vector<TreeNode*> Ans;
        if(l > r){
            Ans.push_back(0);
            return Ans;
        }else{
            
            for(int root = l;root <= r;root++){
                
                auto Left = solve(l, root - 1);
                auto Right = solve(root + 1, r);
                
                
                for(auto leftRoot : Left){
                    for(auto rightRoot : Right){
                        
                        TreeNode* current = new TreeNode(root);
                        current -> left = leftRoot;
                        current -> right = rightRoot;
                        
                        Ans.push_back(current);
                    }
                }
            }
            
        }
        return Ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};