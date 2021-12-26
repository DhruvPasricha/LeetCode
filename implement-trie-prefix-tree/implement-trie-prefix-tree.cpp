class Node {
public:
    unordered_map<char, Node*> children;
    bool isTerminal;

    Node() {
        this->isTerminal = false;
    }
    
    bool exists(char ch) {
        return children.count(ch) > 0;
    }
    
    Node* getChild(char ch) {
        return children[ch];
    }
    
    void insertChild(char ch) {
        children[ch] = new Node;
    }
}; 

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node;
    }
    
    void insert(string word) {
        Node *current = root;
        for(char ch : word) {
            if(not current -> exists(ch)) {
                current -> insertChild(ch);
            }
            current = current -> getChild(ch);
        }
        current -> isTerminal = true;
    }
    
    bool search(string word) {
        Node *current = root;
        for(char ch : word) {
            if(not current -> exists(ch)) {
                return false;
            }
            current = current -> getChild(ch);
        }
        return current -> isTerminal;
    }
    
    bool startsWith(string prefix) {
         Node *current = root;
        for(char ch : prefix) {
            if(not current -> exists(ch)) {
                return false;
            }
            current = current -> getChild(ch);
        }
        return true;
    }
};
