class Solution {
public:
    
    static bool comp(int a, int b){
        string a_ = to_string(a);
        string b_ = to_string(b);
        
        return a_ + b_ > b_ + a_;
    }
    
    string largestNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end(), comp);
        string ans = "";
        for(int x : nums) {
            ans += to_string(x);
        }
        
        int i = 0;
        int n = ans.size();
        
        while(i < n and ans[i] == '0') i++;
        
        if(i == n) return "0";
        
        return ans.substr(i);
    }
};
