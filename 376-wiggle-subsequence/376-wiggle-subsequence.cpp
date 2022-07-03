class Solution {
    void solve(vector<int> &A, stack<pair<int, bool>> &s) {
        for(int &x : A) {
            auto [val, isDecreasing] = s.top();
            if((isDecreasing and x > val) or ((not isDecreasing) and x < val)) {
                s.push({x, not isDecreasing});
            } else {
                s.top().first = x;
            }
        }
    }
public:
    int wiggleMaxLength(vector<int>& nums) {
        stack<pair<int, bool>> s1, s2;
        s1.push({nums[0], true});
        s2.push({nums[0], false});        
        solve(nums, s1);
        solve(nums, s2);
        return max(s1.size(), s2.size());
    }
};
