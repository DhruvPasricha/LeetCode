class Solution {
    
    vector<int> prefix, prefixMin, suffixMin;
    
    void init(vector<int> &gas, vector<int> &cost) {
          
        int n = gas.size();
        
        prefix.assign(n, 0);
        prefix[0] = gas[0] - cost[0]; 
        for(int i = 1;i < n;i++) 
            prefix[i] = prefix[i - 1] + (gas[i] - cost[i]);
        
        prefixMin.assign(n, 0);
        prefixMin[0] = prefix[0];
        for(int i = 1;i < n;i++) 
            prefixMin[i] = min(prefixMin[i - 1], prefix[i]);
        
        
        suffixMin.assign(n, 0);
        suffixMin[n - 1] = prefix[n - 1];
        for(int i  = n - 2;i >= 0;i--) 
            suffixMin[i] = min(suffixMin[i + 1], prefix[i]);
        
    }
    
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      
        init(gas, cost);
        int n = gas.size();
        
        if(prefixMin[n - 1] >= 0) return 0;
        
        for(int i = 1;i < n;i++) {
            
            int rightExtra = prefix[i - 1];  
            int leftRemaining = prefix[n - 1] - rightExtra; 
            
            int leftMin = prefixMin[i - 1] + leftRemaining;
            int rightMin = suffixMin[i] - rightExtra;
            
            if(leftMin >= 0 and rightMin >= 0) return i;
        }
        
        return -1;
    }
};