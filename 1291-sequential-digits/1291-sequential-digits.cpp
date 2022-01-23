class Solution {
    
    
    void insert(char start, set<int> &st) {
        
        string s = "";
        s += start;
        
        while(s.back() != '9' + 1) {
            st.insert(stoll(s));
            s += (s.back() + 1);
        }
        
    }
    
public:
    vector<int> sequentialDigits(int low, int high) {
        
        set<int> sequentialNumbers;
        
        for(char start = '1';start <= '9';start++) 
            insert(start, sequentialNumbers);
        
        
        vector<int> Ans;
        
        auto itr = sequentialNumbers.lower_bound(low);
        
        while(itr != sequentialNumbers.end()) {
            if(*itr > high)
                break;
            Ans.push_back(*itr);
            itr++;
        }
        
        return Ans;
    }
};