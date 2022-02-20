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
    
    
    int solveOptimised(vector<vector<int>> &intervals) {
        
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
           
            if(a[0] == b[0])
                return a[1] > b[1];
            
            return a[0] < b[0];
            
        });
        
        int n = intervals.size();
        int maxCoveredInRight = 0;
        int coveredIntervals = 0;
        
        for(int i = 0; i < n; i++) {
            
            bool isCovered = maxCoveredInRight >= intervals[i][1];
            
            maxCoveredInRight = max(maxCoveredInRight, intervals[i][1]);
            
            coveredIntervals += isCovered;
        }
        
        return n - coveredIntervals;
    }
    
    
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        // int ans = solveBruteForce(intervals);
        int ans = solveOptimised(intervals);
        
        return ans;
        
    }
};