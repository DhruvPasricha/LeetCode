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
public:
    Node* connect(Node* root) {
        
        if(root == NULL) return NULL;
        queue<Node*> q;
        
        Node *prev = NULL; 
        q.push(root);
        q.push(NULL);
        
        while(q.size() > 0) {
            
            auto f = q.front();
            q.pop();
            
            if(f == NULL) {
                if(q.size() > 0) q.push(NULL);
                else break;
            } else { 
                if(prev != NULL) prev -> next = f;
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
            prev = f;
        }
        return root;
    }
};