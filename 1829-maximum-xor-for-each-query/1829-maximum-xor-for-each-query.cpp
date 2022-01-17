class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
       
        int n = nums.size();
        vector<int> Ans(n);
        
        int mask = (1 << maximumBit) - 1;
        int XOR = 0;
        
        for(int &num : nums) XOR ^= num;
        
        for(int i = n - 1;i >= 0;i--) {
            
            int current = XOR ^ mask;
            Ans[n - 1 - i] = current;
            XOR ^= nums[i];
           
        }
        
        return Ans;
        
    }
};