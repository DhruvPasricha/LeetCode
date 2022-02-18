class Solution {

    vector<vector<int>> Ans;
    vector<int> cur;
    
    void solve(vector<int> &freq, int pos, int target) {
        
        
        if(pos == 51) {
            if(target == 0) 
                Ans.push_back(cur);
            return;
        }
        
        solve(freq, pos + 1, target);
        
        int count = 0;
        
        for(int i = 1; i <= freq[pos];i++) {
            
            if(target - (i * pos) < 0)
                break;
            cur.push_back(pos);
            count++;
            solve(freq, pos + 1, target - (i * pos));
        }
        
        while(count--) cur.pop_back();
    }
    
    
public:
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        
        vector<int> freq(51, 0);
        
        for(int x : arr) 
            freq[x]++;
        
        solve(freq, 1, target);
        
        return Ans;
    }
};