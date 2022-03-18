class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        set<int> visited;
        
        for(auto &edge : edges) {
            
            int u = edge[0];
            int v = edge[1];
            
            if(visited.count(u)) return u;
            if(visited.count(v)) return v;
            
            visited.insert(u);
            visited.insert(v);
            
        }
        
        return 1;
        
        
    }
};