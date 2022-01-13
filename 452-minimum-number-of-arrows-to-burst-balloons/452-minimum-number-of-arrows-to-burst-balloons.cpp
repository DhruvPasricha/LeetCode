class Solution {
    
    bool intersecting(vector<int> &current, vector<int> &newOne) {
        
        if(current[0] <= newOne[0]) {
            
            if(current[1] >= newOne[0]) {
                current[0] = newOne[0];
                current[1] = min(newOne[1], current[1]);
            } else {
                return false;
            }
            
        } else {
            
            if(newOne[1] >= current[0]) {
                current[1] = min(current[1], newOne[1]);
            } else {
                return false;
            }           
        }
        return  true;
    }
    
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(), points.end());
        
        
        int n = points.size();
        int ans = 0;
        for(int i = 0;i < n;i++) {
            
            vector<int> current = points[i];
            int j  = i + 1;
            
            while(j < n and intersecting(current, points[j])) j++;
            
            i = j - 1;
            ans++;
        }
        return ans;
    }
};