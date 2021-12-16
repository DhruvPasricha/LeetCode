// Approach
        
// find diameter of each node
// min among them is minimum height
// now all those nodes that have diameter = minimum height will be the part of our answer  
        

#define v vector
class Solution {
    
    
    void dfs(int current, int parent, v<int> Adj[], v<pair<int,int>> &down){
        
        int mx = 0;
        int smx = 0;
        for(int child : Adj[current]){
            if(child != parent){
                dfs(child, current, Adj, down);
                if(down[child].first + 1 >= mx){
                    smx = mx;
                    mx = down[child].first + 1;
                }else if(down[child].first + 1> smx){
                    smx = down[child].first + 1;
                }
            }
        }
        down[current].first = mx;
        down[current].second = smx;
    }
    
    void dfs(int current, int parent, v<int> Adj[], v<pair<int,int>> &down, v<int> &up){
        
        if(parent != -1){
            
            if(down[parent].first == 1 + down[current].first){
                up[current] = 1 + down[parent].second;
            }else{
                up[current] = 1 + down[parent].first;
            }
            up[current] = max(up[current], 1 + up[parent]);
        }
        
        for(int child : Adj[current]){
            if(child != parent){
                dfs(child, current, Adj, down, up);
            }
        }
        
    }
    
    v<int> getDiameters(v<int> Adj[], int n){
        
        v<pair<int,int>> down(n);
        dfs(0, -1, Adj, down);
        
        v<int> up(n);
        dfs(0, -1, Adj, down, up);
        
        v<int> Ans(n);
        
        for(int i = 0;i < n;i++){
            Ans[i] = max(down[i].first, up[i]);
        }
        
        return Ans;
    }
    
    
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        
        v<int> Adj[n];
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            Adj[u].push_back(v);
            Adj[v].push_back(u);
        }
        
        
        v<int> diameter = getDiameters(Adj, n);
        
        int minHeight = INT_MAX; // all values are < INT_MAX
        
        for(int d : diameter){
            minHeight = min(d, minHeight);
        }
        
        v<int> Ans;
        for(int i = 0;i < n;i++){
            int d = diameter[i];
            if(d == minHeight){
                Ans.push_back(i);
            }
        }
        return Ans;
        
    }
};
