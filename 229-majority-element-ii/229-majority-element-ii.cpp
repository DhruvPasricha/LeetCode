class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int ans1 = INT_MAX;
        int ans2 = INT_MAX;
        int count1 = 0;
        int count2 = 0;
        
        for(int &x : nums) {

            if(x == ans1)
                count1++;
            else if(x == ans2)
                count2++;
            else if(count1 == 0) 
                ans1 = x, count1 = 1;
            else if(count2 == 0) 
                ans2 = x, count2 = 1;
            else
                count1--, count2--;
            
            if(count1 == 0) ans1 = INT_MAX;
            if(count2 == 0) ans2 = INT_MAX;
        }
        
        count1 = count2 = 0;
        
        for(int x : nums)
            if(x == ans1) 
                count1++;
            else if(x == ans2)
                count2++;
        
        vector<int> ans;
        
        if(3 * count1 > nums.size())
            ans.push_back(ans1);
        
        
        if(3 * count2 > nums.size())
            ans.push_back(ans2);
        
        return ans;
    }
};