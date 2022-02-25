struct Node{
    int val;
    Node* next;

    Node(int val = -1, Node* next = NULL) {
        this -> val = val;
        this -> next = next;
    }
};


class MyCircularQueue {
    
    Node *head, *tail;
    int size;
    int capacity;
    
public:
    MyCircularQueue(int k) {
        this -> capacity = k;
        this -> head = this -> tail = NULL;
        this -> size = 0;
    }
    
    bool enQueue(int value) {
        
        if(this -> size == this -> capacity) {
            return false;
        }
        
        if(this -> size == 0) {
            this -> head = this -> tail = new Node(value);
        } else {
            this -> tail -> next = new Node(value);
            this -> tail = this -> tail -> next;
        }
        
        this -> tail -> next = this -> head;
        
        this -> size++;
        
        return true;
    }
    
    bool deQueue() {
        
        if(this -> size == 0) {
            return false;
        }
        
        this -> tail -> next = this -> head -> next;
        this -> head = this -> head -> next;
        this -> size--;
        
        return true;
    }
    
    int Front() {
        
        if(this -> size == 0)
            return -1;
        
        return this -> head -> val;
    }
    
    int Rear() {
        
        if(this -> size == 0)
            return -1;
        
        return this -> tail -> val;
    }
    
    bool isEmpty() {
        
        return this -> size == 0;
    }
    
    bool isFull() {
        
        return this -> size == this -> capacity;
    }
};
