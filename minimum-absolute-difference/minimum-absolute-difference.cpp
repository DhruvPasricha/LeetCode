class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        
        int mn = arr[n - 1] - arr[0];
       
        for(int i = 1;i < n;i++){
            mn = min(mn, arr[i] - arr[i-1]);
        }
        
        vector<vector<int>> Ans;
        
        for(int i = 1;i < n;i++){
            if(arr[i] - arr[i-1] == mn){
                Ans.push_back({arr[i-1], arr[i]});
            }
        }
        
        return Ans;
        
    }
};