class Solution {
    int solve(vector<int> &A, int val, bool isDecreasing) {
        int ans = 1;
        for(int &x : A) {
            if((isDecreasing and x > val) or ((not isDecreasing) and x < val)) {
                ++ans;
                isDecreasing = not isDecreasing;
            }
            val = x;
        }
        return ans;
    }
public:
    int wiggleMaxLength(vector<int>& nums) {        
        int val = nums[0];
        bool isDecreasing = true;
        int ans1 = solve(nums, val, isDecreasing);
        isDecreasing = false;
        int ans2 = solve(nums, val, isDecreasing);
        return max(ans1, ans2);
    }
};
