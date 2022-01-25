class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        
        int n = arr.size();
        int i = 1;
        
        // strictly increasing
        while(i < n and arr[i] > arr[i - 1]) 
            i++;
        
        if(i == n or i == 1) 
            return false;
        
        // strictly decreasing
        while(i < n and arr[i] < arr[i - 1])
            i++;
        
        return i == n;
    }
};