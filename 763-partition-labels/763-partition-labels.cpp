class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int> lastOccurence(26);
        
        int n = s.size();
        
        for(int i = 0; i < n; i++)
            lastOccurence[s[i] - 'a'] = i;
        
        
        int curLen = 0;
        int curMaxIndex = 0;
        vector<int> Ans;
        
        for(int i = 0; i < n; i++) {
            
            curLen++;
            curMaxIndex = max(curMaxIndex, lastOccurence[s[i] - 'a']);
            
            if(curMaxIndex == i) {
                Ans.push_back(curLen);
                curLen = curMaxIndex = 0;
            }
        }
        
        return Ans;
    }
};