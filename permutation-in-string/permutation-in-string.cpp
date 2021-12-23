class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        
        vector<int> required(26);
        for(int i = 0;i < m;i++) required[s1[i] - 'a']++;
        
        int n = s2.size();
        vector<vector<int>> pre(26, vector<int>(n, 0));
        for(int i = 0;i < n;i++){
            pre[s2[i]-'a'][i]++;
        }
        
        for(int i = 0;i < 26;i++){
            for(int j = 1;j < n;j++){
                pre[i][j] += pre[i][j-1];
            }
        }
        
        int start = 0;
        int end = m - 1;
        
        
        while(end < n) {
            
            vector<int> current(26);
            for(int i = 0;i < 26;i++){
                current[i] = pre[i][end];
                if(start > 0) current[i] -= pre[i][start - 1];
            }
            
            if(current == required) return true;
            start++;
            end++;
        }
        
        return false;
        
        
    }
};
