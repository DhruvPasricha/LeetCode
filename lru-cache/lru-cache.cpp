class Node {
    Node *prev = NULL;
    Node *next = NULL;
    int key;
    
    Node(int v = 0) {
        key = v;
    }
    
    friend class DoublyLinkedList;
    friend class LRUCache;
};


class DoublyLinkedList {
  
    Node *head = NULL;
    Node *tail = NULL;
    int size = 0;
    
    int clearLRU() {
        int ans = head -> key; 
        erase(head);
        return ans;
    }
    
    Node* append(int key) {
        Node *current = new Node(key);
        if(head == NULL) {
            head = tail = current;
        }else {
            tail -> next = current;
            current -> prev = tail;
            tail = current;
        }
        size++;
        return current;
    }
    
    void erase(Node *node) {
        
        if(node == NULL) return;
        
        if(node == head) {
            if(node -> next) node -> next -> prev = NULL;
            else tail = node -> prev;
            head = node -> next;
        } else {
            node -> prev -> next = node -> next;
            if(node -> next) node -> next -> prev = node -> prev;
            else tail = node -> prev; 
        }
        delete node;
        size--;
    }
    friend class LRUCache;
    
};

class LRUCache {
    DoublyLinkedList list;
    unordered_map<int, pair<int, Node*>> Info; 
    int limit = 0;
public:
    LRUCache(int capacity) {
        limit = capacity;
    }
    
    int get(int key) {
        
        if(Info.count(key)) {
            
            list.erase(Info[key].second);
            
            Info[key].second = list.append(key);
            return Info[key].first;
        } 
        
        return -1;
    }
    
    void put(int key, int value) {
        
        if(Info.count(key)) {
            list.erase(Info[key].second);
        } else if(list.size == limit){
            int lruKey = list.clearLRU();
            Info.erase(lruKey);   
        }
        Info[key].second = list.append(key);
        Info[key].first = value;
    }
};
