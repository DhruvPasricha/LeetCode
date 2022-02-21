class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int ans = -1;
        int count = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            count == 0 and (bool)(ans = nums[i]);
            count += 2 * (ans == nums[i]) - 1;
        }
        
        return ans;
    }
};