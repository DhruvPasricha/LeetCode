class Solution {

    unordered_map<char, string> mp;
public:
    Solution() {
        string s = "";
        for(char ch = 'a' ; ch <= 'z'; ch++) s += ch;
        int j = 0;
        for(char i = '2';i <= '9';i++){
            string current = s.substr(j, 3);
            j += 3;
            if(i == '7' or i == '9') current += s[j++];
            mp[i] = current;
        }
    }
    
    vector<string> letterCombinations(string digits) {
        
        if(digits.length() == 0) return {};
        
        vector<string> Ans;
        Ans.push_back("");
        
        for(char d : digits){
            string letters = mp[d];
            vector<string> temp = Ans;
            
            for(int i = 1;i < letters.length();i++)
                for(int j = 0;j < temp.size();j++)
                    Ans.push_back(temp[j]);
                
            int k = 0;
            for(int i = 0;i < letters.length();i++)
                for(int j = 0;j < temp.size();j++)
                    Ans[k++] += letters[i];
            
        }
        return Ans;
    }
};