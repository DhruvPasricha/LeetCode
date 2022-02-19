class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = n - 2;
        int ans = 0;
        while(i >= 0) {
            ans += nums[i];
            i -= 2;
        }
        return ans;
    }
};