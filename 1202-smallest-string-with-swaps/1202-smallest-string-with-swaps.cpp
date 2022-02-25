struct DSU{
    
    vector<int> parent;
    vector<int> size;
    
    DSU(int n) {
        parent.resize(n, 0);
        size.assign(n, 1);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }
    
    
    int getParent(int x) {
        
        if(x == parent[x])
            return x;
        
        return parent[x] = getParent(parent[x]);
    }
    
    void join(int u, int v){
        
        u = getParent(u);
        v = getParent(v);
        
        if(u == v)
            return;
        
        if(size[u] < size[v])
            swap(u, v);
        
        parent[v] = u;
        size[u] += size[v];
    }
    
};


class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        int n = s.size();
        
        DSU dsu(n);
        
        for(auto &pair : pairs) {
            
            int u = pair[0];
            int v = pair[1];
            
            dsu.join(u, v);
        }
        
        unordered_map<int, set<int>> mp;
        
        for(int i = 0;i < n; i++)
            mp[dsu.getParent(i)].insert(i);
        
        
        for(auto &group : mp) {
            
            map<char, int> freq;
                
            for(auto &it : group.second)
                freq[s[it]]++;
            
            for(auto &it : group.second) {
                char smallest = freq.begin()->first;
                s[it] = smallest;
                freq[smallest]--;
                if(freq[smallest] == 0)
                    freq.erase(smallest);
            }
            
        }
        
        return s;
    }
};
