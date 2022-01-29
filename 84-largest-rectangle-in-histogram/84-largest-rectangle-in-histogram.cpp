class Solution {
    
    int solve(vector<int> &heights, int l, int r) {
        
        if(l > r) 
            return 0;
        
        auto minIndex = min_element(heights.begin() + l, heights.begin() + r + 1) - heights.begin();
        auto maxIndex = max_element(heights.begin() + l, heights.begin() + r + 1) - heights.begin();
        
        int width = r - l + 1;
        int height = heights[minIndex];
        int currentAns = width * height;
        
        if(heights[minIndex] == heights[maxIndex])
            return currentAns;
        
        return max({currentAns, solve(heights, l, minIndex - 1), solve(heights, minIndex + 1, r)});
        
    }
    
public:
    int largestRectangleArea(vector<int>& heights) {
        return solve(heights, 0, (int)heights.size() - 1);
    }
};