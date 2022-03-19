class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> index;
        
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            int req = target - nums[i];
            
            if(index.count(req))
                return {index[req], i};
            
            index[nums[i]] = i; 
        }
        
        return {};
    }
};