class Solution {
    
    unordered_map<string, char> mp;
    vector<bool> visited;
    
    
    bool check(const string &currentString, const char &currentChar) {
        
        if(mp.count(currentString)) {
            if(mp[currentString] != currentChar) return false;
        } else if(visited[currentChar - 'a']){
            return false;
        } else {
            mp[currentString] = currentChar;
        }
            
        visited[currentChar - 'a'] = true;
        
        return true;
    }
    
    
public:
    
    Solution() {
        visited.assign(26, false);    
    }
    
    bool wordPattern(string pattern, string s) {
        
        int n = s.length();
        int m = pattern.length();
        
        int j = 0;
        
        for(int i = 0;i < n;i++, j++) {
            
            string current = "";
            
            while(i < n and s[i] != ' ') {
                current += s[i];
                i++;
            }
                        
            bool ok = j < m and check(current, pattern[j]);
            
            if(not ok) return false;
        }
        return j == m;
    }
};