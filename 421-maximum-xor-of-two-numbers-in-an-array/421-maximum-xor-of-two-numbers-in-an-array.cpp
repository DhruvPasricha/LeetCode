class Node {
    vector<Node*> children;
    
    bool hasChild(int ch) {
        return children[ch] != NULL;
    }
    
    void insertChild(int ch) {
        children[ch] = new Node();
    }
    
    Node* getChild(int ch) {
        return children[ch];
    }
    
    Node() {
        children.assign(2, NULL);
    }
    
    friend class Trie;  
};

class Trie {
    
    Node *root = NULL;
    
public:
    Trie() {
        root = new Node();
    }        
    
    
    void insert(int n) {
        
        Node *current = root;
        
        for(int i = 30;i >= 0;i--) {
            int bit = (n & (1 << i));
            bit = min(1, bit);
            if(!current->hasChild(bit)) {
                current->insertChild(bit);
            }
            
            current = current->getChild(bit);
        }
    }
    
    int bestXor(int n) {
        
        Node* current = root;
        int ans = 0;
        for(int i = 30;i >= 0;i--) {
            
            int bit = (n & (1 << i));
            bit = min(bit, 1);
            int req = bit ^ 1;
            
            if(current->hasChild(req)) {
                ans += (1 << i);
                current = current->getChild(req);
            } else {
                current = current->getChild(bit);
            }
        }
        
        return ans;
    } 
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        int ans = 0;
        for(int &x : nums) {
            t.insert(x);
            ans = max(ans, t.bestXor(x));
        }
        return ans;
    }
};