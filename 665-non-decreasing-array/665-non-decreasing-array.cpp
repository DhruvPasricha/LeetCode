class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        int n = nums.size();
        vector<bool> prefix(n, true), suffix(n, true);
        
        for(int i = 1; i < n; ++i) prefix[i] = prefix[i - 1] and nums[i] >= nums[i - 1];
        for(int i = n - 2; i >= 0; --i) suffix[i] = suffix[i + 1] and nums[i] <= nums[i + 1];
        
        for(int i = 0; i < n; ++i) {
            int prev = INT_MIN;
            int next = INT_MAX;
            bool isSortedPre = true;
            bool isSortedSuf = true;
            if(i > 0) prev = nums[i - 1], isSortedPre = prefix[i  - 1];
            if(i < n - 1) next = nums[i + 1], isSortedSuf = suffix[i + 1];
            if(prev <= next and isSortedPre and isSortedSuf) return true;
        }
        
        return false;
        
    }
};
