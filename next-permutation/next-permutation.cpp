class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        int i = n - 2;
        while(i >= 0) {
            
            if(nums[i] < nums[i + 1]) {
                reverse(nums.begin() + i + 1, nums.end());
                int idx = upper_bound(nums.begin() + i + 1, nums.end(), nums[i]) - nums.begin();
                swap(nums[i], nums[idx]);
                return;
            }
            
            i--;
        }
        // if no next permutation exists
        reverse(nums.begin(), nums.end());
    }
};
