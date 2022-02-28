class Solution {
    
    
    int setBit(int n, int i) {
        
        return n | (1 << i);
    }
    
public:
    int shortestPathLength(vector<vector<int>>& graph) {
     
        int n = graph.size();
        
        int ans = INT_MAX;
        
        for(int start = 0; start < n; start++) {
            
            int dp[n][(1 << n)];
        
            memset(dp, -1, sizeof(dp));
        
            queue<pair<int,int>> q; // {node, mask}
            
            int mask = setBit(0, start);
            
            q.push({start, mask});
            
            dp[start][mask] = 0;
            
            while(q.size() > 0) {
                
                
                auto [node, mask] = q.front();
                
                if(mask  + 1 == (1 << n))
                    ans = min(ans, dp[node][mask]);
                
                q.pop();
                
                
                for(auto nb : graph[node]) {
                    
                    int mask_ = setBit(mask, nb);
                    
                    if(dp[nb][mask_] == -1) {
                        dp[nb][mask_] = dp[node][mask] + 1;
                        q.push({nb, mask_});
                    }
                    
                }
                
            }
            
        }
        
        return ans;
    }
};