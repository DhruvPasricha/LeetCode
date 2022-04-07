class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq;
        
        for(int stone: stones) 
            pq.push(stone);
        
        
        while(pq.size() > 1) {
            
            auto f1 = pq.top();
            pq.pop();
            auto f2 = pq.top();
            pq.pop();
            
            if(f1 - f2)
                pq.push(f1 - f2);
        }
        
        
        return (pq.size()) ? pq.top() : 0;
    }
};