class Solution {
    vector<vector<int>> Ans;
    vector<int> current;
    
    void solve(vector<int> &nums, int pos) {
        
        if(pos == (int)nums.size()) {
            Ans.push_back(current);
            return;
        }
        
        solve(nums, pos + 1);
        
        current.push_back(nums[pos]);
        solve(nums, pos + 1);
        current.pop_back();
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(nums, 0);
        return Ans;
    }
};