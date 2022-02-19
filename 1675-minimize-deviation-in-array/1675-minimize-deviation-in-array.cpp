#define v vector
#define pii pair<int, int>

class Solution {
    
    int getMin(int x) {
        
        while(x % 2 == 0)
            x /= 2;
        
        return x;
    }
    
public:
    int minimumDeviation(vector<int>& nums) {
        
        priority_queue<pii, v<pii>, greater<pii>> pq;
        
        int n = nums.size();
        
        int ans = INT_MAX;
        
        int mx = 0;
        for(int i = 0;i < n;i++) {
            
            if(nums[i] & 1)
                nums[i] *= 2;
            
            int current = getMin(nums[i]);
            pq.push({current, i});
            mx = max(mx, current);
        }
        
        while(pq.size() == n) {
            
            auto f = pq.top();
            pq.pop();
            
            ans = min(ans, mx - f.first);
            
            f.first *= 2;
            
            mx = max(mx, f.first);
            
            if(f.first <= nums[f.second])
                pq.push(f);
    
        }
        
        return ans;
    }
};
