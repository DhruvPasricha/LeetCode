class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        int ans = n + 1;
        
        int64_t sum = 0;
        int j = 0;
        
        for(int i = 0; i < n; i++) {
            
            sum += (int64_t)nums[i];
            
            while(j <= i and sum - nums[j] >= target) {
                sum -= nums[j];
                j++;
            }
            
            if(sum >= target)
                ans = min(ans, i - j + 1);
        }
        
        return ans % (n + 1);
    }
};