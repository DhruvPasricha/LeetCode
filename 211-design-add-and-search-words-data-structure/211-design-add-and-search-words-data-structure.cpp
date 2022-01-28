class TrieNode {
    
    unordered_map<char, TrieNode*> children;
    bool isTerminal = false;
    
    friend class Trie;
    
    TrieNode* getChild(char ch) {
        if(this -> children.count(ch) == 0)
            this -> children[ch] = new TrieNode();
        return this -> children[ch];
    }
    
    bool hasChild(char ch) {
        return this -> children.count(ch) > 0;
    }
};

class Trie {
    
    TrieNode* root = NULL;
    
    
    bool searchPattern(TrieNode* r, string &s, int idx) {
        
        if(idx == s.size()) return r->isTerminal;
        
        if(s[idx] != '.') {
            
            if(r -> hasChild(s[idx])) 
                return searchPattern(r -> getChild(s[idx]), s, idx + 1);
            else
                return false;
        }
        bool ans = false;
        for(auto &itr : r -> children) {
            ans |= searchPattern(itr.second, s, idx + 1);
        }
        return ans;
    }
    
public:
    Trie() {
       root = new TrieNode(); 
    }
    
    
    void insert(string &s) {
        
        auto r = this -> root;
        for(auto &ch : s) {
            r = r -> getChild(ch);
        }
        r -> isTerminal = true;
    }
    
    bool search(string &s) {
        return this -> searchPattern(this-> root, s, 0);
    }
};


class WordDictionary {
    Trie t;
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        t.insert(word);
    }
    
    bool search(string word) {
        return t.search(word);
    }
    
};
