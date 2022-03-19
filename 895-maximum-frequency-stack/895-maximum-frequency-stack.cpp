class Node{
 public:
    Node *prev;
    int val;
    Node *next;
    Node *prevSame;
    int index;
    
    Node(int v, int t) {
        
        val = v;
        prev = next = prevSame = NULL;
        index = t;
    }
};

class FreqStack {
    
    
    Node *head;
    Node *tail;
    
    unordered_map<int, Node*> topMostAddress;
    
    map<int, set<pair<int,int>, greater<pair<int,int>>>, greater<int>> mp; // {freq -> {index, val}}
    
    unordered_map<int, int> freq; // freq
    
    int t = 0;
    
public:
    FreqStack() {
        
        head = tail = new Node(INT_MIN, ++t); // dummy head
    }
    
    void push(int val) {
        
        auto temp = new Node(val, ++t);
        
        if(freq[val] > 0) {
            temp -> prevSame = topMostAddress[val];
            auto itr = mp[freq[val]].find({temp -> prevSame -> index, val});
            mp[freq[val]].erase(itr);
        }
        
        freq[val]++;
        
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
        
        topMostAddress[val] = temp;
        
        mp[freq[val]].insert({t, val});
        
    }
    
    int pop() {
        
        
        auto &st = mp.begin()->second;
        
        int val = st.begin()->second;
        
        auto temp = topMostAddress[val];
        
        // delete temp
        temp -> prev -> next = temp -> next;
        
        if(temp -> next)
          temp -> next -> prev = temp -> prev;
        else
            tail = temp -> prev;
        
        mp[freq[val]].erase({temp->index, val});
        
         
        if(mp[freq[val]].size() == 0)
            mp.erase(freq[val]);
        
        freq[val]--;
        
        if(freq[val]) {
            topMostAddress[val] = temp -> prevSame;
            mp[freq[val]].insert({topMostAddress[val]->index, val});
        }
        
        return val;
    }
};
