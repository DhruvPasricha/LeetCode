class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        int ans = n + 1;
        
        queue<int> q;
        int64_t sum = 0;
        
        for(int i = 0; i < n; i++) {
            
            q.push(nums[i]);
            sum += (int64_t)nums[i];
            
            while(q.size() and sum - q.front() >= target) {
                sum -= q.front();
                q.pop();
            }
            
            if(sum >= target)
                ans = min(ans, (int)q.size());
        }
        
        return ans % (n + 1);
    }
};