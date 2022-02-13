class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n = nums.size();
        int count = (1 << n);
        
        vector<vector<int>> Ans;
        
        for(int i = 0; i < count; i++) {
            
            vector<int> current;
            
            for(int j = 0; j < n; j++) {
                if((1 << j) & i)
                    current.push_back(nums[j]);
            }
            
            Ans.push_back(current);
            
        }
        
        return Ans;
    }
};

