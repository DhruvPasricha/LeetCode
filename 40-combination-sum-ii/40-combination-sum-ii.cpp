

class Solution {

    vector<vector<int>> Ans;
    vector<int> cur;
    
    void solve(vector<int> &freq, int prev, int target) {
        
        if(target == 0) {
            Ans.push_back(cur);    
        }
        
        int limit = min(30, target);
        
        for(int i = prev; i <= limit;i++) {
            
            if(freq[i] > 0) {
                
                freq[i]--;
                cur.push_back(i);
                solve(freq, i, target - i);
                freq[i]++;
                cur.pop_back();
                
            }
        }
    }
    
    
public:
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        
        vector<int> freq(51, 0);
        
        for(int x : arr) 
            freq[x]++;
        
        solve(freq, 0, target);
        
        return Ans;
    }
};