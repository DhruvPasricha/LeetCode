class Solution {
    void connect(Node *&src, Node *&dest) {
        src -> next = dest;
    }
public:
    Node* connect(Node* root) {
        if(root == NULL or root -> left == NULL) return root;
        if(root -> left) connect(root -> left, root -> right);
        if(root -> next) connect(root -> right, root -> next -> left);
        root->left = connect(root -> left);
        root->right = connect(root -> right);
        return root;
    }
};