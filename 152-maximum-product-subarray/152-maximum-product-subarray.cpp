class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        
        const int inf = 1e6;
        
        vector<int> bestPositive(n, inf);
        vector<int> bestNegative(n, inf);
        
        if(nums[0] > 0) 
            bestPositive[0] = nums[0];
        else if(nums[0] == 0) 
            bestPositive[0] = bestNegative[0] = nums[0];
        else 
            bestNegative[0] = nums[0];
        
        // inf means does not exist
        for(int i = 1;i < n;i++) {
            
            if(nums[i] > 0) {
                
                bestPositive[i] = (bestPositive[i - 1] == inf) ? nums[i] : max(nums[i], nums[i] * bestPositive[i - 1]);
                bestNegative[i] = (bestNegative[i - 1] == inf) ? inf : (nums[i] * bestNegative[i - 1]);
                
            } else if(nums[i] == 0) {
            
                bestPositive[i] = bestNegative[i] = 0;
                
            } else{
                
                bestPositive[i] = (bestNegative[i - 1] == inf) ? inf : nums[i] * bestNegative[i - 1];
                
                bestNegative[i] = (bestPositive[i - 1] == inf) ? nums[i] : min(nums[i], nums[i] * bestPositive[i - 1]); 
                
            }
            
            
        }
        
        
        int ans = -inf;
        
        
        for(int i = 0;i < n;i++) {
            if(bestPositive[i] != inf)
                ans = max(ans, bestPositive[i]);
            if(bestNegative[i] != inf)
                ans = max(ans, bestNegative[i]);
        }
        
        return ans;
    }
};
