class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int i = 0;
        int j = 0;
        int n = nums.size();
        while(i < n){
            
            int cur = nums[i];
            nums[j++] = nums[i++];
            
            if(i < n and nums[i] == cur) nums[j++] = nums[i++]; 
            
            while(i < n and nums[i] == cur) i++;            
        }
        
        return j;
    }
};