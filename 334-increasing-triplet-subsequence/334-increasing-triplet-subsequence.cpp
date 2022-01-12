class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n = nums.size();
        int prefixMin = nums[0];
        vector<int> suffixMax(n, nums[n - 1]);
        
        for(int i = n - 2;i >= 0;i--) suffixMax[i] = max(suffixMax[i + 1], nums[i]);
        
        for(int i = 1;i < n - 1;i++) {
            
            prefixMin = min(nums[i - 1], prefixMin);
            auto suffixMax_ = suffixMax[i + 1];
            
            if(nums[i] > prefixMin and nums[i] < suffixMax_) return true;
        }
        
        return false;
        
    }
};

// Time : O(N)
// Space : O(N)
 