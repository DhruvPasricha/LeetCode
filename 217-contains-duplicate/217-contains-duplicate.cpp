class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        set<int> st;
        
        for(int x : nums) st.insert(x);
        
        return st.size() < nums.size();
    }
};