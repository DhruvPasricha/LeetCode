class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int ans = 0;
        int count = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            
            if(count == 0)
                ans = nums[i];
            
            if(ans == nums[i])
                count++;
            else
                count--;
            
        }
        
        return ans;
    }
};