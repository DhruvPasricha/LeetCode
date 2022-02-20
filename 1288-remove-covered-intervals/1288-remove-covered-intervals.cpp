class Solution {
    
    
    
    int solveBruteForce(vector<vector<int>> &intervals) {
        
        int n = intervals.size();
        
        int coveredIntervals = 0;
        
        for(int i = 0; i < n; i++) {
            
            bool isCovered = false;
            
            for(int j = 0; j < n; j++)
                isCovered |= (i != j and intervals[j][0] <= intervals[i][0] and intervals[i][1] <= intervals[j][1]);
            
            coveredIntervals += isCovered;
        }
        
        return n - coveredIntervals;
        
    }
    
    
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        int ans = solveBruteForce(intervals);
        
        return ans;
        
    }
};