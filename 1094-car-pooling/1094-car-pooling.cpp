class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        #define v vector
        
        v<int> difArr(1002);
        
        for(auto &trip : trips) {
            int p = trip[0];
            int l = trip[1];
            int r = trip[2];

            difArr[l] += p;
            difArr[r] -= p;
        }
        
        for(int i = 1;i <= 1000;i++)
            difArr[i] += difArr[i - 1];
        
        for(int i = 0;i <= 1000;i++)
            if(difArr[i] > capacity)
                return false;
        
        return true;
        
    }
};

