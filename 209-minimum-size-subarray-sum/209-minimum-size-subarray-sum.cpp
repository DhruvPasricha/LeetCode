class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        
        queue<int> q;
        int sum = 0;
        int ans = n + 1;
        
        for(int i = 0;i < n; i++) {
            
            q.push(nums[i]);
            sum += nums[i];
            
            while(q.size() > 0) {
                if(sum - q.front() < target)
                    break;
                sum -= q.front();
                q.pop();
            }
            
            if(sum >= target)
                ans = min(ans, (int)q.size());
        }
        
        return ans % (n + 1);
    }
};
