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
    
    map<Node*, Node*> mp; // old -> new
    
public:
    Node* cloneGraph(Node* node) {
        
        if(node == NULL)
            return node;
        
        if(mp.count(node))
            return mp[node];
        
        Node* ans = new Node(node->val);
        
        mp[node] = ans;
        
        for(auto nb : node->neighbors) {
            ans->neighbors.push_back(cloneGraph(nb));
        }
        
        return ans;
    }
};