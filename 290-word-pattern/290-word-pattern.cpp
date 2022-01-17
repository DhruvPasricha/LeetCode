class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        unordered_map<string, char> mp;
        unordered_set<char> visited;
        
        int n = s.length();
        int m = pattern.length();
        
        int j = 0;
        
        for(int i = 0;i < n;i++, j++) {
            
            string current = "";
            
            while(i < n and s[i] != ' ') {
                current += s[i];
                i++;
            }
            
            if(mp.count(current)) {
                if(j >= m or mp[current] != pattern[j]) return false;
            } else if(visited.count(pattern[j])){
                return false;
            } else {
                mp[current] = pattern[j];
            }
            
            visited.insert(pattern[j]);
        }
        return j == m;
    }
};