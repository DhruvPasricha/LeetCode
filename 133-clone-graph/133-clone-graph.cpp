/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    
    unordered_map<Node*, Node*> mp; // old -> new
    
    
    Node* dfs(Node* node) {
        
        if(node == NULL)
            return node;
        
        if(mp.count(node))
            return mp[node];
        
        Node* ans = new Node(node->val);
        
        mp[node] = ans;
        
        for(auto nb : node->neighbors) {
            ans->neighbors.push_back(dfs(nb));
        }
        
        return ans;
        
        
    } 
    
    
    Node* bfs(Node* node) {
        
        if(node == NULL)
            return node;
        
        mp[node] = new Node(node -> val);
        
        queue<Node*> q;
        
        q.push(node);
        
        
        while(q.size()) {
            
            auto f = q.front();
            
            q.pop();
            
            
            for(auto nb : f -> neighbors) {
                
                if(mp.count(nb) == 0) {
                    mp[nb] = (nb != NULL) ? new Node(nb -> val) : NULL;
                    if(nb != NULL)
                        q.push(nb);
                }
                
                mp[f]->neighbors.push_back(mp[nb]);
            }
                    
        }
    
        return mp[node];
        
    }
    
    
public:
    Node* cloneGraph(Node* node) {
        
        return bfs(node);
       
    }
};