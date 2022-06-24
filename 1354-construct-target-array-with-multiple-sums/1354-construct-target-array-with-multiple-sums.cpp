class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        priority_queue<long long> pq;
        long long sum = 0;
        
        for(int &x: target) {
            pq.push(x);
            sum += (long long)x;
        }
                
        while(pq.size() > 0) {
            
            if(pq.top() == 1)
                return true;
            
            auto mx = pq.top();
            pq.pop();
            
            sum -= mx;
            
            if(sum <= 0)
                return false;
            
            long long k = ((mx - pq.top()) / sum) + ((mx - pq.top()) % sum != 0);
            long long num = mx - k * sum;
            
            if(num < 1 or num == mx)
                return false;
            
            sum += num;
            pq.push(num);
        }
        
        
        return false;

    }
};
