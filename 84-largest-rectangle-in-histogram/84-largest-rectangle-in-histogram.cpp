class Solution {
    
    vector<int> nextSmallerLeft, nextSmallerRight;
    
    void preCompute(vector<int> &heights) {
        
        int n = heights.size();
        stack<int> st;
        
        // left
        nextSmallerLeft.assign(n, -1);
        for(int i = 0;i < n;i++) {
            
            while(st.size() > 0 and heights[st.top()] >= heights[i]) {
                st.pop();
            }
            
            if(st.size() > 0) {
                nextSmallerLeft[i] = st.top();
            }
            
            st.push(i);
        }
        
        // resetting the stack
        while(st.size() > 0) {
            st.pop();
        }
        
        // right
        nextSmallerRight.assign(n, n);
        for(int i = n - 1;i >= 0;i--) {
            
            while(st.size() > 0 and heights[st.top()] >= heights[i]) {
                st.pop();
            }
            
            if(st.size() > 0) {
                nextSmallerRight[i] = st.top();
            }
            
            st.push(i);
        }
    }
    
    
    int getLeftStrechCount(vector<int> &height, int x) {
		return x - nextSmallerLeft[x] - 1;
	}
	
	int getRightStrechCount(vector<int> &height, int x) {
        return nextSmallerRight[x] - x - 1;
	}	
	

	int solve(vector<int> &heights) {
		int n = heights.size();
		int ans = 0;
		for(int i = 0;i < n;i++) {
			int height = heights[i];
			int width = 1 + getLeftStrechCount(heights, i) + getRightStrechCount(heights, i);
            ans = max(ans, height * width);	
		}
		return ans;
	}
    
public:
    int largestRectangleArea(vector<int>& heights) {
        preCompute(heights);
        return solve(heights);
    }   
};