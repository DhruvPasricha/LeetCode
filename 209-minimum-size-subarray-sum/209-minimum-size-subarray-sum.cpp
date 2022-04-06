class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        
        int n = nums.size();
        int ans =  n + 1;
        
        
        vector<int64_t> pre(n);
        pre[0] = nums[0];
        
        for(int i = 1; i < n; i++) {
            pre[i] = nums[i];
            pre[i] += pre[i - 1];
        }
        
        for(int i = 0; i < n; i++) {
            
            
            int l = -1;
            int r = i + 1;
            
            
            while(r - l > 1) {
                
                int m = (l + r) / 2;
                
                if(pre[i] - pre[m] + nums[m] >= target)
                    l = m;
                else
                    r = m;
                
            }
            
            if(l >= 0)
                ans = min(ans, i - l + 1);
            
            
        }
        
        return ans % (n + 1);
    }
};