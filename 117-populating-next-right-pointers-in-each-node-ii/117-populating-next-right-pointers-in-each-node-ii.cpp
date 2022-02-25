/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    
    unordered_map<int, Node*> mp;
    
public:
    Node* connect(Node* root, int level = 0) {
        
        if(root == NULL)
            return root;
        
        if(mp.count(level))
            mp[level] -> next = root;
        
        mp[level] = root;
        
        root -> left = connect(root->left, level + 1);
        root -> right = connect(root->right, level + 1);
        
        return root;
    }
};