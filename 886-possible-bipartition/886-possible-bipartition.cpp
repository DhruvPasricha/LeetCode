class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<int> color(n + 1, -1);
        
        vector<int> Adj[n + 1];
        
        for(auto &edge : dislikes) {
            int u = edge[0], v = edge[1];
            Adj[u].push_back(v);
            Adj[v].push_back(u);
        }
        
        for(int i = 1;i <= n;i++) {
            
            if(color[i] != -1)
                continue;
            
            queue<int> q;    
            q.push(i);
            color[i] = 0;

            while(q.size() > 0) {

                auto f = q.front();
                q.pop();

                int childrenColor = 1 - color[f];

                for(int children : Adj[f])
                    if(color[f] == color[children])
                        return false;
                    else if(color[children] == -1)
                        color[children] = childrenColor, q.push(children);

            }
        }
        
        
        return true;
    }
};