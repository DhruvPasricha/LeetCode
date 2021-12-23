class Solution {
public:
    
    void solve(int num, unordered_map<int,int> &choosen,unordered_map<int,int> &mp, vector<vector<int>> &Ans) {
        
        if(num == -11){
            vector<int> current;
            for(auto itr : choosen) {
                int f = itr.second;
                while(f--) current.push_back(itr.first);
            }
            Ans.push_back(current);
            return;
        }
        
        int freq = mp[num];
        
        for(int i = 0;i <= freq;i++) {
            choosen[num] = i;
            solve(num - 1, choosen, mp, Ans);
        }
        
        choosen[num] = 0;
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        for(int i = 0;i < nums.size();i++) mp[nums[i]]++;
        unordered_map<int, int> choosen; 
        vector<vector<int>> Ans;
        solve(10, choosen, mp, Ans);
        
        return Ans;
    }
};