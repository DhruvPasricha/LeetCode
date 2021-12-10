class FrontMiddleBackQueue {
    deque<int> q1, q2;
    int size;
    public:
    
    FrontMiddleBackQueue() {
        size = 0;
    }
    
    void balance(){
        
        size = q1.size() + q2.size();
        
        int left = size / 2;
        int right = size - left;
        
        
        while(q1.size() < left){
            q1.push_back(q2.front());
            q2.pop_front();
        }
        
        while(q2.size() < right){
            q2.push_front(q1.back());
            q1.pop_back();
        }
    }
    void pushFront(int val) {
        q1.push_front(val);
        balance();
    }
    
    void pushMiddle(int val) {
        q1.push_back(val);
        balance();
    }
    
    void pushBack(int val) {
        q2.push_back(val);
        balance();
    }
    
    int popFront() {
        if(size == 0) return -1;
        if(size == 1) swap(q1, q2);
        
        int ans = q1.front();
        q1.pop_front();
        balance();
        
        return ans;
    }
    
    int popMiddle() {
        if(size == 0) return -1;
        
        int ans = (size & 1) ? q2.front() : q1.back();
        
        if(size & 1) q2.pop_front();
        else q1.pop_back();
        
        balance();
        
        return ans;
    }
    
    int popBack() {
        if(size == 0) return -1;
        
        int ans = q2.back();
        q2.pop_back();
        balance();
        
        return ans;
    }
};