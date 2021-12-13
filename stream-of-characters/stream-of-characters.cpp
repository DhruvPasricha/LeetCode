class Node{
  public:
    bool isTerm;
    unordered_map<char, Node*> children;
    char val;
    Node(char val = '\0'){
        isTerm = false;
        this->val = val;
    }
};


class Trie{
  public:
    Node *root = new Node; 
    
    void insert(string &s){
        
        Node *r = root;
        for(char ch : s){
            if(r -> children.count(ch) == 0) r -> children[ch] = new Node(ch);
            r = r -> children[ch];
        }
        r -> isTerm = true;
    }
    
    bool search(string &s){
        
        Node *r = root;
        for(char ch : s){
            if(r -> isTerm) return true;
            if(r -> children.count(ch) == 0) break;
            r = r -> children[ch];
        }
        
        return r -> isTerm;
    }
    
    void print(){
        
        queue<Node*> q;
        q.push(root);
        
        while(q.size() > 0){
            
            auto f = q.front();
            cout << f->val << ": ";
            
            for(auto c : f -> children){
                cout << c.first << ", ";
                q.push(c.second);
            }
            cout << endl;
            q.pop();
        }
    }
};

class StreamChecker {
    string s;
    Trie t;
    int limit = 0;
public:
    StreamChecker(vector<string>& words) {
        for(string &word : words){
            reverse(word.begin(), word.end());
            t.insert(word);
            limit = max(limit, (int) word.size());
        }
    }
    
    bool query(char letter) {
        s = letter + s;
        if(s.length() > limit) s = s.substr(0, limit);
        bool ans = t.search(s);
        return ans;
    }
};
