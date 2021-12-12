class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        k %= n;
        int j = n - k;
        if(j < 0 or j >= n) return;
        reverse(nums.begin(), nums.begin() + j);
        reverse(nums.begin() + j, nums.end());
        reverse(nums.begin(), nums.end());
    }
};