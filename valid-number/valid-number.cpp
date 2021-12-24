class Solution {
    
    bool isDigit(char d) {
        return '0' <= d and d <= '9';
    }
    
    bool isInteger(string s) {
        int i = 0;
        if(s[0] == '+' or s[0] == '-') i++;
        int d = 0;
        while(i < (int)s.size()) {
            if(not isDigit(s[i])) {
                return false;
            }
            i++;
            d++;
        }
        return d > 0;
    }
public:
    bool isNumber(string s, bool req = false) {
        
        // make sure of decimal
        int i = 0;
        int n = s.size();
        if(s[i] == '+' or s[i] == '-') i++;
        
        int Pred = 0;
        while(i < n and isDigit(s[i])) i++, Pred++;
        
        int Suff = 0;
        if(s[i] == '.') {
            i++;
            while(i < n and isDigit(s[i])) i++, Suff++;
        }
        if(i == n) return Pred or Suff;
        cout << Pred << " " << Suff << endl;
        // make sure of e
        if((Pred or Suff) and (s[i] == 'e' or s[i] == 'E')) {
            return isInteger(s.substr(i + 1));
        }
        
        return false;
    }
};