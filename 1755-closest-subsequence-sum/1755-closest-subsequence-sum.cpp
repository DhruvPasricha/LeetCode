class Solution {
    
    
    void solve(vector<int> &nums, int start, int end, vector<int> &A) {
        
        A.push_back(0);
        for(int i = start;i <= end;i++) {
            int n1 = A.size();
            for(int j = 0;j < n1;j++) {
                A.push_back(nums[i] + A[j]);
            }
        }
    }
    
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        
        int n = nums.size();
        vector<int> s1;
        vector<int> s2;
        
        solve(nums, 0, n/2, s1);
        solve(nums, n/2 + 1, n - 1, s2);
        
        set<int> ss2(s2.begin(), s2.end());
        
        int ans = INT_MAX;
        
        for(int &f : s1) {
            
            auto itr = ss2.lower_bound(goal - f);
            int cur = INT_MAX;
            if(itr != ss2.end()) {
                cur = min(cur, abs(goal - (*itr + f)));
            }
            if(itr != ss2.begin()) {
                itr--;
                cur = min(cur, abs(goal - (*itr + f)));
            }
            ans = min(ans, cur);

        }
        
        return ans;        
    }
};