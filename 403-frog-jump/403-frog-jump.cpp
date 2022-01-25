class Solution {
    int dp[2001][2001];
    
    int solve(vector<int> &A, int current, int prev) {
        
        if(current + 1 == A.size())
            return true;
        
        int &ans = dp[current][prev];
        if(ans != -1) return ans;
        
        int prevJump = A[current] - A[prev];
        
        int dx[] = {-1, 0, 1};
        
        ans = false;
        
        for(int i = 0;i < 3;i++) {
            
            int next = prevJump + dx[i] + A[current];
            
            if(next == A[current])
                continue;
            
            auto itr = lower_bound(A.begin(), A.end(), next);
            
            if(itr == A.end() or *itr != next)
                continue;
            
            ans |= solve(A, itr - A.begin(), current);
                
        }
        
        return ans;
    }
    
public:
    bool canCross(vector<int>& stones) {
        memset(dp, -1, sizeof(dp));
        return (stones[1] == 1 and solve(stones, 1, 0));
    }
};