class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int l = 0;
        int r = nums.size() - 1;
        auto &A = nums;
        
        while(l <= r) {
            
            int m = (l + r) / 2;
            
            if(nums[m] == target or nums[l] == target or nums[r] == target)
                return true;
            
            if(A[l] < A[m]) {
                
                if(target > A[m])
                    l = m + 1;
                else
                    l++, r--;
                
            } else if(A[l] > A[m]) {
                
                if(target < A[m])
                    r = m - 1;
                else
                    l++, r--;
                
            } else {
                
                l++, r--;
            }
    
        }
        
        return false;
    }
};