class Solution {
    vector<int> *A;
    int n;
    vector<bool> visited;
    queue<int> q;
    map<int, set<int>> locations;
    vector<int> steps;
    
    void init(vector<int> &arr) {
        this->A = &arr;
        this->n = arr.size();
        for(int i = 0;i < n;i++) {
            locations[arr[i]].insert(i);
        }
        visited.assign(n ,false);
        steps.assign(n, INT_MAX);
    }
    
    bool safe(int i) {
        return  i >= 0 and i < n;
    }
    
    void insert(int cur, int parent) {
        visited[cur] = true;
        steps[cur] = steps[parent] + 1;
        q.push(cur);
    }
    
    int bfs() {
        vector<int> &arr = *A;
        q.push(0);
        visited[0] = true;
        steps[0] = 0;
        while(q.size() > 0){
            
            auto i = q.front();
            if(i == n - 1) return steps[i];
            q.pop();
            
            if(safe(i - 1) and not visited[i - 1]) {
                insert(i - 1, i);
            }
            
            if(safe(i + 1) and not visited[i + 1]) {
                insert(i + 1, i);
            }
            
            if(locations.count(arr[i]) == 0) continue;
            
            for(const int &nb : locations[arr[i]]) {
                if(not visited[nb]) {
                    insert(nb, i);
                }
            }
            
            locations[arr[i]].clear();
        
        }
        return steps[n - 1];
    }
    
public:
    
    int minJumps(vector<int>& arr) {
        
        init(arr);
        int ans = bfs();
        return ans;
    }
};