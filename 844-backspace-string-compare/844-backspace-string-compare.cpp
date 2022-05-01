class Solution {
    
    
public:
    bool backspaceCompare(string s, string t) {
    
        auto f = [&] (string &s) {
            
            string ans = "";
            
            for(char &ch : s) {
                
                if(ch == '#') {
                    if(ans.size()) ans.pop_back();
                } else{ 
                    ans += ch;
                }
            }
            
            return ans;
            
        };
        
        
        s = f(s);
        t = f(t);
        
        return s == t;
    }
};