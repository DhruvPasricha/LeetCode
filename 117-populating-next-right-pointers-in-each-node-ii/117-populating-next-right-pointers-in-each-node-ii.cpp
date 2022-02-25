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
        
        if(root == NULL)
            return NULL;
        
        queue<Node*> q;
        
        q.push(root);
        q.push(NULL);
        
        Node* prev = NULL;
        
        while(q.size()) {
            
            auto f = q.front();
            q.pop();
            
            if(prev != NULL)
                prev -> next = f;
            
            prev = f;
            
            // level has ended
            if(f == NULL) {
                
                if(q.size()) 
                    
                    q.push(NULL);
            
            } else {
                
                if(f -> left) 
                    q.push(f -> left);
                
                if(f -> right) 
                    q.push(f -> right);
                
            }
            
        }
        
        return root;
    }
};