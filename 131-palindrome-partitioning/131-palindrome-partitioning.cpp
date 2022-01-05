class Solution {
    
    vector<vector<string>> Ans;
    vector<string> current;
    string prev;
    
    bool isPalindrome(string &s) {
        
        if(s == "") return false;
        int l = 0;
        int r = (int)s.size() - 1; 
        while(l < r) if(s[l++] != s[r--]) return false;
        return true;
    }
    void solve(string &s, int pos) {
        
        if(pos == s.length()) {
            if(isPalindrome(prev)) {
                current.push_back(prev);
                Ans.push_back(current);
                current.pop_back();
            }
            return;
        }
        
        // add to this one
        prev += s[pos];
        solve(s, pos + 1);
        prev.pop_back();
        
        // start a new one from this
        if(isPalindrome(prev)) {
            current.push_back(prev);
            prev = "";
            prev += s[pos];
            solve(s, pos + 1);
            prev = current.back();
            current.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        solve(s, 0);
        return Ans;
    }
};