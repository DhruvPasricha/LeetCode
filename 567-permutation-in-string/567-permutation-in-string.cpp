class Solution {
    
    unordered_map<int, int> mp;
    
    void insert(char &ch, int x) {
        this->mp[ch] += x;
        if(this->mp[ch] == 0)
            mp.erase(ch);
    }
    
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1.length() > s2.length()) 
            return false;

        for(char &ch : s1) 
            this->insert(ch, -1);
        
        int k = s1.length();
        
        for(int i = 0;i < k;i++)
            this->insert(s2[i], 1);
        
        if(this->mp.size() == 0)
            return true;
        
        int n = s2.length();
        
        for(int i = 0, j = k; j < n; i++, j++) {
            this->insert(s2[i], -1);
            this->insert(s2[j], 1);  
            if(this->mp.size() == 0) 
                return true;
        }
        
        return false;
    }
};