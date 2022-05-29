class Solution {
    
    set<pair<int, int>> used;
    vector<int> depth;
    vector<int> up;
    vector<int> dp;
    vector<vector<int>> ans;
    
    void dfs(int x, vector<int> Adj[], vector<bool> &visited, int lvl = 0) {
        
        depth[x] = lvl;
        visited[x] = true;
        
        for(int &child : Adj[x])
            if(not visited[child])
                used.insert({x, child}), dfs(child, Adj, visited, lvl + 1);
        
    }
    
    
    
    void solve(int x, vector<int> Adj[], vector<bool> &visited) {
        
        visited[x] = true;
        dp[x] = up[x];    
        for(int &child : Adj[x]) {
            if(not visited[child]) { 
                
                // {x, child}
                solve(child, Adj, visited);
                if(dp[child] > depth[x]) {
                    ans.push_back({child, x});
                }
                dp[x] = min(dp[x], dp[child]);
            }
        }
        
    }
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        depth.assign(n, 0);
        up.assign(n, INT_MAX);
        dp.assign(n, INT_MAX);
        
        vector<int> Adj[n];
        vector<bool> visited(n);
        
        for(auto &edge : connections) {
            int u = edge[0], v = edge[1];
            Adj[u].push_back(v);
            Adj[v].push_back(u);
        }
        
        dfs(0, Adj, visited);
        
        for(auto &edge: connections) {
            
            int u = edge[0];
            int v = edge[1];
            if(depth[u] > depth[v])
                swap(u, v);
            
            if(used.count({u, v}))
                continue;
            
            
            up[v] = min(up[v], depth[u]);
        }
        
        visited.assign(n, false);
        
        solve(0, Adj, visited);
        
        return ans;
    }
};