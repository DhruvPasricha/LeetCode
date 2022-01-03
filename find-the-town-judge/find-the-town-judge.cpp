class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> indegree(n + 1);
        vector<int> outdegree(n + 1);
        
        for(auto &it : trust) {
            int a = it[0];
            int b = it[1];
            outdegree[a]++;
            indegree[b]++;
        }
        
        int count = 0;
        int ans = -1;
        
        for(int i = 1;i <= n;i++){
            if(indegree[i] == n - 1 and outdegree[i] == 0) ans = i, count++;            
        }
        if(count > 1) ans = -1;
        return ans;
    }
};