class Solution {
    
    int solve(vector<int> &A, vector<int> &B, int x) {
        
        int ans = 0;
        int n = A.size();
        
        for(int i = 0; i < n; i++) {
            
            if(A[i] == x) 
                continue;
            
            if(B[i] == x) 
                ans++;
            else 
                return INT_MAX;
        }
        
        return ans;
        
        
    }
    
    
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        int ans = INT_MAX;
        
        for(int i = 1;i <= 6;i++) {
            
            int ans1 = solve(tops, bottoms, i);
            int ans2 = solve(bottoms, tops, i);
            
            ans = min({ans, ans1, ans2});
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};