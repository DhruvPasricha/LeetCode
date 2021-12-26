class Solution {
    
    int solve(vector<int> &A) {
        
        int n = A.size();
        int ans = 0;
        map<int,int> mp;
        for(int i = 0;i < n;i++){
            
            auto itr = mp.lower_bound(A[i]);
            
            if(itr == mp.end()) {
                mp[A[i]] = i;
            } else {
                ans = max(ans, A[i] * (i - itr->second));
            }
        }
        return ans;
    }
    
public:
    int maxArea(vector<int>& height) {
        int ans = solve(height);
        reverse(height.begin(), height.end());
        ans = max(ans, solve(height));
        return ans;
    }
};
