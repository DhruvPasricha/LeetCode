class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> Ans;
        
        int n = nums.size();
        
        int i = 0;
        
        while(i < n) {
              
            int j = i;
            int64_t expected = nums[i];
            
            while(j < n and nums[j] == expected) {
                j++;
                expected++;
            }
            
            int start = nums[i];
            int end = nums[j - 1];
            
            Ans.push_back(to_string(start));
            
            if(end > start) 
                Ans.back() += "->" + to_string(end);
            
            i = j;
            
        }
        
        return Ans;
    }
};