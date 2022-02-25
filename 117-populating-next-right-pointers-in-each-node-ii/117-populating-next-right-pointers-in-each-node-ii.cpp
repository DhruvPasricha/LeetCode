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
    
    
    void connect(vector<Node*> &currentLevel) {
        
        int n = currentLevel.size();
        
        for(int i = 1; i < n; i++) {
            currentLevel[i - 1] -> next = currentLevel[i];
        }
    }
    
public:
    Node* connect(Node* root) {
        
        if(root == NULL)
            return NULL;
        
        queue<Node*> q;
        
        q.push(root);
        q.push(NULL);
        
        vector<Node*> currentLevel;
        
        while(q.size()) {
            
            auto f = q.front();
            q.pop();
            
            // level has ended
            if(f == NULL) {
                
                connect(currentLevel);
                currentLevel.clear();
                
                if(q.size()) 
                    q.push(NULL);
            
            } else {
                
                currentLevel.push_back(f);
                
                if(f -> left) 
                    q.push(f -> left);
                
                if(f -> right) 
                    q.push(f -> right);
                
            }
            
        }
        
        return root;
    }
};