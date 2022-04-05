class Solution
{
public:
    int maxArea(vector<int> &height)
    {

        int i = 0;
        int j = height.size() - 1;
        int ans = 0;
        
        while(i < j) {
            
            int cur = (j - i) * min(height[j], height[i]);
            ans = max(ans, cur);
            
            if(height[i] <= height[j])
                i++;
            else
                j--;
            
        }
        
        return ans;
    }
};
