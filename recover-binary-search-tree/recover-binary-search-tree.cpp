class Solution {
    vector<TreeNode*> A;
public:
    
    
    void inorder(TreeNode* root, TreeNode* &prev) {
        if(root == NULL) return;
        inorder(root->left, prev);
        if(prev != NULL and prev->val > root->val) {
            A.push_back(prev);
            A.push_back(root);
        }
        prev = root;
        inorder(root->right, prev);
    }
    
    void recoverTree(TreeNode* root) {
        // key idea : swapping two nodes will sort the array 
        // => there will be irregualrites at most two places
        // ........ < a > b < .......................
        //            _____
        // ........ < a > b < ..... < c > d .........
        //            _____           _____
        TreeNode* prev = NULL;
        inorder(root,prev);
        if(A.size() == 2) swap(A[0]->val, A[1]->val);
        if(A.size() == 4) swap(A[0]->val, A[3]->val);
    }
};